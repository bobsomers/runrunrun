#pragma once

#include <vector>
#include "entity.h"

namespace ngn {


class OutOfBoundsException: public std::exception
{
  virtual const char* what() const throw()
  {
    return "That entity ID either does not exist or was deleted.";
  }
};

// TODO: Replace the vectors and naive mallocs with an Allocator.

template <class E>
class Pool
{
public:
	Pool():mNumEntities(0){};
	~Pool(){};

	Handle add(E entity)
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
		Handle handle = mElements[mNumEntities].handle;
		handle.idx = mNumEntities;
		mElements[mNumEntities].handleChanged(handle);

		mNumEntities++;
		return handle;
	};

	E* get(unsigned idx)
	{
		if (idx >= mNumEntities)
			throw OutOfBoundsException();

		return &mElements[idx];
	};

	void del(unsigned idx)
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
	};

	void swap(unsigned a, unsigned b)
	{
		E temp = mElements[a];

		mElements[a] = mElements[b];
		mElements[b] = temp;

		Handle handle_a = mElements[a].handle;
		Handle handle_b = mElements[b].handle;
		handle_a.idx = a;
		handle_b.idx = b;

		mElements[a].handleChanged(handle_a);
		mElements[b].handleChanged(handle_b);
	};

	unsigned count(){ return mNumEntities; }
protected:
	std::vector<E> mElements;
	unsigned mNumEntities;

};

} // namespace ngn