#include "ngn/component.h"
#include <exception>

namespace ngn {

extern ContentManager CONTENT_MANAGER;

GameObject::GameObject()
{

}

GameObject::GameObject( std::initializer_list<ComponentType> componentTypes )
{
	for (auto componentType : componentTypes)
	{
		Handle handle = CONTENT_MANAGER.createComponent(componentType, this->handle);
		this->addComponent(handle);
	}
}

GameObject::GameObject( std::initializer_list<Component**> componentPtrs )
{
	for (auto componentPtr : componentPtrs)
	{
		Handle handle = CONTENT_MANAGER.addComponent(*componentPtr, this->handle);
		this->addComponent(handle);

		// Now delete and set the remote pointer to null, since we've passed on the data
		// and we don't want stale pointers
		delete *componentPtr;
		*componentPtr = nullptr;
	}
}

GameObject::~GameObject()
{

}

void GameObject::addComponent(Handle handle)
{
	if (handle == nullHandle) return;
	mComponents[handle.type] = handle;
}

Component* GameObject::getComponentByType(ComponentType type)
{
	try {
		return CONTENT_MANAGER.getComponent(mComponents[type]);
	} catch (std::exception e) {
		return nullptr;
	}
}

void GameObject::update()
{
	printf("GameObject with ID %d running update\n", this->handle.id);
	// This is a slower, less cache-friendly process of updating a game object's
	// components. We should normally not do it this way.
	for (auto kv : mComponents)
	{
		printf("Updating update on component type %d and index %d\n", kv.first, kv.second.idx);
		CONTENT_MANAGER.getComponent(kv.second)->update(*this);
	}
}


} // namespace ngn