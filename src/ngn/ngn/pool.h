#pragma once

#include <vector>
#include "entity.h"

namespace ngn {

// TODO: Replace the vectors and naive mallocs with an Allocator.

template <class E>
class Pool
{
public:
	Pool():mNumEntities(0){};
	~Pool(){};

	unsigned add(E entity);
	E get(unsigned idx);
	void del(unsigned idx);
	void swap(unsigned a, unsigned b);

	unsigned count(){ return mNumEntities; }
protected:
	std::vector<E> mElements;
	unsigned mNumEntities;

};


class PoolManager
{
public:
	PoolManager(){}
	~PoolManager(){};

	virtual void* getObject(Handle handle) = 0;
};

} // namespace ngn