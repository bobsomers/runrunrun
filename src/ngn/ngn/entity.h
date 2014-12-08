#pragma once

namespace ngn {

/*
 * The purpose of the entity class is to give two important pieces of 
 * functionality to elements stored in our pools. Its state (whether it
 * is alive or not) and its id (the index in the pool's array.)
 */
class Entity
{
public:
	bool alive;
	unsigned id;

	Entity():alive(true){};
	virtual ~Entity(){};

private:
	// When an entity is moved in a pool, this function is invoked.
	// If someone is watching this class, we'll want to let them know.
	virtual void changedId() = 0;
};

} // namespace ngn