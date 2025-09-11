#include "Cat.hpp"

Cat::Cat(void): Animal(), _brain(new Brain())
{
	_type = "Cat";
	std::cout << "Cat spawn with default constructor." << std::endl;
}

Cat::Cat(const Cat& source): Animal(source), _brain(new Brain(*source._brain))
{
	std::cout << "Cat spawn with coppy constructor." << std::endl;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat despawn." << std::endl;
}

Cat&	Cat::operator=(const Cat& source)
{
	if (this != &source)
	{
		_type = "Cat";
		delete	_brain;
		_brain = new Brain(*source._brain);
	}
	std::cout << "Cat spawn with coppy assignment oparetor." << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "meaw meaw" << std::endl;
}

Brain*	Cat::getBrain(void) const
{
	return (_brain);
}
