#include <entityx/entityx.h>

using namespace entityx;

int main()
{
	EntityX entityx;

	entityx::Entity entity = entityx.entities.create();

	return 0;
}