#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	_type = "Cat";
	std::cout << "Cat spawn with default constructor." << std::endl;
}

Cat::Cat(const Cat& source): Animal(source)
{
	std::cout << "Cat spawn with coppy constructor." << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat despawn." << std::endl;
}

Cat&	Cat::operator=(const Cat& source)
{
	if (this != &source)
	{
		_type = "Cat";
	}
	std::cout << "Cat spawn with coppy assignment oparetor." << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "meaw meaw" << std::endl;
}
