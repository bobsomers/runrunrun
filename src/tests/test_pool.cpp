#include <ngn/pool.h>
#include <pool.cpp>
#include <ngn/entity.h>

namespace ngn {

class TestEntity : public Entity
{
public:
	TestEntity(int someval):Entity(), someval(someval) {}
	~TestEntity(){}

	void handleChanged() { printf("Changed my handle's idx to %d\n", handle.idx); }

	int someval;
};

} // namespace ngn


using namespace ngn;

void printPool(Pool<TestEntity> pool)
{
	printf("-------------------\n");
	for (unsigned idx=0; idx < pool.count(); idx++)
	{
		TestEntity e = pool.get(idx);
		printf("Value: %d, ID: %d\n", e.someval, e.handle.idx);
	}
}

int main() {

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


	return 0;
}