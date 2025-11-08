#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <typeinfo>

Base* generate(void)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	int ran = std::rand();

	if (ran % 3 == 0)
	{
		std::cout << "A" << std::endl;
		return (new A());
	}
	else if (ran % 3 == 1)
	{
		std::cout << "B" << std::endl;
		return (new B());
	}
	std::cout << "C" << std::endl;
	return (new C());
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "this object type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "this object type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "this object type C" << std::endl;
}

void identify(Base& p)
{
	try {
		A a = dynamic_cast<A&>(p);

		std::cout << "this ref type A" << std::endl;
	}
	catch (std::bad_cast& b) {}

	try {
		B b = dynamic_cast<B&>(p);

		std::cout << "this ref type B" << std::endl;
	}
	catch (std::bad_cast& b) {}

	try {
		C c = dynamic_cast<C&>(p);

		std::cout << "this ref type C" << std::endl;
	}
	catch (std::bad_cast& b) {}
}

int main(void)
{
	Base* ran;
	A a;
	B b;
	C c;

	ran = generate();
	identify(ran);
	identify(a);
	identify(b);
	identify(c);
	delete ran;
}
