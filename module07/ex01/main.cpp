#include "iter.hpp"

void rot3(char& c)
{
	c += 3;
}

void print(const char& c)
{
	std::cout << c;
}

int main(void)
{
	// test non const
	char arr[4] ={'a', 'b', 'c', '\0'};

	std::cout << "before: " << arr << std::endl;
	::iter(arr, 3, rot3);
	std::cout << "after: " << arr << std::endl;

	// test const
	const char arr2[4] ={'a', 'b', 'c', '\0'};
	::iter(arr2, 3, print);
}
