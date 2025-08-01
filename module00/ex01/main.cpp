#include <cstdlib>
#include <iostream>
#include "PhoneBook.hpp"

static int	check_phone(std::string line)
{
	static PhoneBook	book;

	if (line == "SEARCH")
		book.SEARCH();
	else if (line == "ADD")
		book.ADD();
	else if (line == "clear")
		system("clear");
	else if (line == "EXIT")
		return (1);
	return (0);
}

int	main(void)
{
	std::string	line;

	system("clear");
	while (1)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, line) || check_phone(line))
			break ;
	}
}
