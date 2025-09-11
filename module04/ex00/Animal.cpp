#include "Animal.hpp"

Animal::Animal(void): _type("")
{
	std::cout << "Animal spawn with default constructor." << std::endl;
}

Animal::Animal(const Animal& source): _type(source._type)
{
	std::cout << "Animal spawn with coppy constructor." << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal despawn." << std::endl;
}

Animal&	Animal::operator=(const Animal& source)
{
	if (this != &source)
	{
		_type = source._type;
	}
	std::cout << "Animal spawn with coppy assignment operator." << std::endl;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << ". . ." << std::endl;
}

std::string		Animal::getType(void) const
{
	return (_type);
}
