#include "ngn/pool.h"
#include <exception>

namespace ngn {


class OutOfBoundsException: public std::exception
{
  virtual const char* what() const throw()
  {
    return "That entity ID either does not exist or was deleted.";
  }
} myex;


template <class E>
unsigned Pool<E>::add(E entity)
{
	// Give the entity a new id
	entity.id = mNumEntities;
	entity.alive = true;
	// We may have a number of elements in our vector which are marked as dead.
	// We don't want to add to the very end of the array for efficiency reasons.
	if (mNumEntities < mElements.size())
	{
		mElements[mNumEntities] = entity;
	}else{
		mElements.insert(mElements.begin() + mNumEntities, entity);
	}


	// Tell its friends that it just changed location. This is *probably* unnecessary
	// because it will likely not be given a parent until AFTER it is created.
	mElements[mNumEntities].changedId();
	mNumEntities++;

	return mNumEntities-1;
}

template <class E>
E Pool<E>::get(unsigned id)
{
	if (id >= mNumEntities)
		throw OutOfBoundsException();

	return mElements[id];
}

template <class E>
void Pool<E>::del(unsigned id)
{
	// For efficiency's sake, instead of leaving 'killed' entities in the middle
	// of the array, swap them with the last living entity. From time to time we
	// will have to prune the entities at the end of the list.
	if (mNumEntities < 1) return;
	// Entity has already been deleted.
	if (id >= mNumEntities) return;

	E toMove = mElements[mNumEntities-1];
	// Kill the entity and put it at the end of the living list
	mElements[id].alive = false;
	mElements[id].id = mNumEntities - 1;
	mElements[mNumEntities-1] = mElements[id];
	// Put the living entity in its place and tell its friends they've moved
	toMove.id = id;
	mElements[id] = toMove;
	mElements[id].changedId();
	// This is PROBABLY not necessary, since no one cares where it lives after it
	// dies.. unless we plan on having zombie entities!
	mElements[mNumEntities-1].changedId();
	mNumEntities--;
}

} // namespace ngn