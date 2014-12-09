#include "ngn/component.h"
#include "ngn/message.h"

namespace ngn {


void Component::handleChanged(Handle handle)
{
	// Let the parent entity know
	if (mParent == nullHandle) return;

	// Grab the component

	// Tell it the handle has been changed

	// Finally, set local handle
	this->handle = handle;
}


Component* ContentManager::getComponent(Handle handle)
{
	if (handle.type == TYPE_LOCATION) {
		return (Component*)mLocationComponents.get(handle.idx);
	}

	return nullptr;
}


Handle ContentManager::addComponent(Component *component, Handle parent)
{
	switch (component->handle.type)
	{
		case TYPE_LOCATION:
			printf("Created new location component\n");
			return mLocationComponents.add(*static_cast<LocationComponent*>(component));
			break;
		default:
			return nullHandle;
	}
}


Handle ContentManager::createComponent(ComponentType type, Handle parent)
{
	switch (type)
	{
		case TYPE_LOCATION:
			printf("Created new location component\n");
			return mLocationComponents.add(LocationComponent(parent));
			break;
		default:
			return nullHandle;
	}
}

// GLOBALS
ContentManager CONTENT_MANAGER;

} // namespace ngn