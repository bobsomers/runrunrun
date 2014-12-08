#pragma once

#include <vector>
#include "entity.h"

namespace ngn {

template <class E>
class Pool
{
public:
	Pool():mNumEntities(0){};
	~Pool(){};

	unsigned add(E entity);
	E get(unsigned id);
	void del(unsigned id);

	unsigned count(){ return mNumEntities; }
protected:
	std::vector<E> mElements;
	unsigned mNumEntities;

};

} // namespace ngn