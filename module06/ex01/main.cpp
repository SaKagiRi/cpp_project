#include "Serializer.hpp"

int main(void)
{
	Data a;

	a.content = "hello world";
	uintptr_t res = Serializer::serializer(&a);
	std::cout << Serializer::deserialize(res)->content << std::endl;
}
