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
	mElements[mNumEntities].handle.idx = mNumEntities;
	mElements[mNumEntities].handleChanged();

	return mNumEntities++;
}

template <class E>
E Pool<E>::get(unsigned idx)
{
	if (idx >= mNumEntities)
		throw OutOfBoundsException();

	return mElements[idx];
}


template <class E>
void Pool<E>::swap(unsigned a, unsigned b)
{
	E temp = mElements[a];

	mElements[a] = mElements[b];
	mElements[b] = temp;

	mElements[a].handle.idx = a;
	mElements[b].handle.idx = b;

	mElements[a].handleChanged();
	mElements[b].handleChanged();
}


template <class E>
void Pool<E>::del(unsigned idx)
{
	// For efficiency's sake, instead of leaving 'killed' entities in the middle
	// of the array, swap them with the last living entity. From time to time we
	// will have to prune the entities at the end of the list.
	if (mNumEntities < 1) return;
	// Entity has already been deleted.
	if (idx >= mNumEntities) return;

	this->swap(idx, mNumEntities-1);
	mElements[mNumEntities-1].alive = false;

	mNumEntities--;
}

} // namespace ngn