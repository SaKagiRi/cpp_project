#include <iostream>
#include <list>
#include "easyfind.hpp"

int main(void)
{
	std::list<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	char *v;

	std::cout << *easyfind(a, 1) << std::endl;
	std::cout << *easyfind(a, 2) << std::endl;
	std::cout << *easyfind(a, 3) << std::endl;
	try{
		std::cout << *easyfind(a, 5) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
