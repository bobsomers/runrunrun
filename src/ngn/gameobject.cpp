#include "ngn/component.h"

namespace ngn {


GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

void GameObject::addComponent(Handle handle)
{
	if (handle == nullComponent) return;

	mComponents.push_back(handle);
}

Component* GameObject::getComponent(ComponentType type)
{
	// Grab whatever component
	return nullptr;
}

void GameObject::update()
{
	// This is a slower, less cache-friendly process of updating a game object's
	// components. We should normally not do it this way.
	
	// Loop through the components

	// Grab the memory location from the pool manager

	// Run update()
}


} // namespace ngn