#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	_type = "Dog";
	std::cout << "Dog spawn with default constructor." << std::endl;
}

Dog::Dog(const Dog& source): Animal(source)
{
	std::cout << "Dog spawn with coppy constructor." << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog despawn." << std::endl;
}

Dog&	Dog::operator=(const Dog& source)
{
	if (this != &source)
	{
		_type = "Dog";
	}
	std::cout << "Dog spawn with coppy assignment oparetor." << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "hong hong" << std::endl;
}
