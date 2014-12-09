#include "ngn/component.h"
#include "ngn/message.h"

namespace ngn {


void Component::handleChanged()
{
	// Let the parent entity know
	if (mParent == nullComponent) return;

	// Grab the component

	// Tell it the handle has been changed
}

} // namespace ngn