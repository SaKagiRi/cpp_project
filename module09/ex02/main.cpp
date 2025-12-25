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

	std::cout << RED "Before: " RESET; a.printALlItem(); std::cout << std::endl;
	a.sort();
	b.sort();
	c.sort();
	std::cout << YELLOW "After:  " RESET; a.printALlItem(); std::cout << std::endl;

	std::cout << "Time to process a range of " RED << a.size() << RESET " elements with " YELLOW "[std::list]  " RESET ": " RED << a.getTime() << RESET " us." << std::endl;
	std::cout << "Time to process a range of " RED << b.size() << RESET " elements with " YELLOW "[std::deque] " RESET ": " RED << b.getTime() << RESET " us." << std::endl;
	std::cout << "Time to process a range of " RED << c.size() << RESET " elements with " YELLOW "[std::vector]" RESET ": " RED << c.getTime() << RESET " us." << std::endl;
	}catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
