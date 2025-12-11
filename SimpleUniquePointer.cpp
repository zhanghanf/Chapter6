#include "SimpleUniquePointer.h"
#include<cstdio>
#include<utility>
struct Tracer {
	Tracer(const char* n) : name(n) {
		printf("Tracer %s constructed.\n", name);
	}
	~Tracer() {
		printf("Tracer %s destructed.\n", name);
	}
private:
	const char* name;
};
void consumer(SimpleUniquePointer<Tracer> com_ptr) {
	printf("In consumer function.0x%p\n",com_ptr.get());
}
int main()
{
	auto ptr1 = SimpleUniquePointer<Tracer>(new Tracer("A"));
	printf("ptr1 holds Tracer at 0x%p\n", ptr1.get());
	consumer(std::move(ptr1));
	printf("main holds Tracer at 0x%p\n", consumer.get());
	return 0;
}