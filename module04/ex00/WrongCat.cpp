#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat spawn with default constructor." << std::endl;
}

WrongCat::WrongCat(const WrongCat& source): WrongAnimal(source)
{
	std::cout << "WrongCat spawn with coppy constructor." << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat despawn." << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& source)
{
	if (this != &source)
	{
		_type = "WrongCat";
	}
	std::cout << "WrongCat spawn with coppy assignment oparetor." << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "meaw meaw" << std::endl;
}
