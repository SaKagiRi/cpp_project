#include "PmergeMe.hpp"

int main(int c, char **v)
{
	std::string input;

	if (c == 1)
	{
		std::cout << "Usage: ./PmergeMe <numbers>" << std::endl;
		return (1);
	}
	for (int i = 1; i < c; i++)
	{
		input += v[i];
		if (i + 1 < c)
			input += " ";
	}
	try{
	PmergeMe<std::list> a;
	PmergeMe<std::deque> b;
	PmergeMe<std::vector> c;

	a.insert(input);
	b = a;
	c = a;
	std::cout << YELLOW "------List-----" RESET << std::endl;
	// a.printALlItem();
	// std::cout << a.size() << std::endl;
	// a.sort();
	// std::cout << (a.is_sort() ? "sorted." : "not sorted.") << std::endl;
	// std::cout << "time: " << a.getTime() << std::endl;
	// a.printALlItem();
	std::cout << YELLOW "===============" RESET << std::endl << std::endl;
	std::cout << YELLOW "-----deque-----" RESET << std::endl;
	// b.printALlItem();
	b.sort();
	std::cout << (b.is_sort() ? "sorted." : "not sorted.") << std::endl;
	std::cout << "time: " << b.getTime() << std::endl;
	// b.printALlItem();
	std::cout << YELLOW "===============" RESET << std::endl << std::endl;
	std::cout << YELLOW "-----vector----" RESET << std::endl;
	// c.printALlItem();
	c.sort();
	std::cout << (c.is_sort() ? "sorted." : "not sorted.") << std::endl;
	std::cout << "time: " << c.getTime() << std::endl;
	// c.printALlItem();
	std::cout << YELLOW "===============" RESET << std::endl << std::endl;
	}catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	// a.getT().push_back(10);
	// std::cout <<  a.getT()[0] << std::endl;
	// PmergeMe<std::vector> b = a;
	//
	// b.getT().push_back(11);
	// // std::cout <<  a.getT()[0] << std::endl;
	// b.printALlItem();
}
