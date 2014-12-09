#include <ngn/pool.h>
#include <ngn/component.h>
#include <ngn/entity.h>

namespace ngn {

extern ContentManager CONTENT_MANAGER;

class TestEntity : public Entity
{
public:
	TestEntity(int someval):Entity(), someval(someval) {}
	~TestEntity(){}

	void handleChanged(Handle handle) 
	{
		printf("Changed my handle's idx from %d to %d\n", this->handle.idx, handle.idx);
		this->handle = handle;
	}

	int someval;
};

} // namespace ngn


using namespace ngn;

void printPool(Pool<TestEntity> pool)
{
	printf("-------------------\n");
	for (unsigned idx=0; idx < pool.count(); idx++)
	{
		TestEntity *e = pool.get(idx);
		printf("Value: %d, ID: %d\n", e->someval, e->handle.idx);
	}
}

int main() {

	printf("\nTesting generic pool functionality.\n");
	printf("-----------------------------------\n");
	Pool<TestEntity> pool;

	// Add several entities to the pool
	pool.add(TestEntity(1));
	pool.add(TestEntity(2));
	pool.add(TestEntity(3));
	pool.add(TestEntity(4));

	// Print what the pool looks like now
	printPool(pool);

	// Remove entity with id 2 (should be swapped with entity id 3)
	pool.del(2);

	// Print the pool
	printPool(pool);

	// Add a new entity. This one should slip into #2's old slot
	pool.add(TestEntity(5));

	printPool(pool);


	printf("\nTesting Content Manager w/ Components.\n");
	printf("--------------------------------------\n");

	GameObject obj1, obj2, obj3;

	obj1.handle.idx = 1;

	Handle handle = CONTENT_MANAGER.createComponent(TYPE_LOCATION, obj1.handle);
	obj1.addComponent(handle);

	LocationComponent* lc = (LocationComponent*)obj1.getComponentByType(TYPE_LOCATION);
	lc->position.x = 1.5;

	obj2 = GameObject({TYPE_LOCATION});
	((LocationComponent*)obj2[TYPE_LOCATION])->position.x = 2.5;

	lc = new LocationComponent();
	lc->position.x = 3.5;
	obj3 = GameObject({
		(Component**)&lc
	});

	if (lc == nullptr) printf("YAY\n");

	// ((LocationComponent*)c)->position.x = 10.5;

	obj1.update();
	obj2.update();
	obj3.update();


	return 0;
}