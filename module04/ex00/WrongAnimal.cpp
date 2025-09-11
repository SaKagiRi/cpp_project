#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("WrongAnimal")
{
	std::cout << "WrongAnimal spawn with default constructor." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& source): _type(source._type)
{
	std::cout << "WrongAnimal spawn with coppy constructor." << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal despawn." << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& source)
{
	if (this != &source)
	{
		_type = source._type;
	}
	std::cout << "WrongAnimal spawn with coppy assignment operator." << std::endl;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << ". . ." << std::endl;
}

std::string		WrongAnimal::getType(void) const
{
	return (_type);
}
