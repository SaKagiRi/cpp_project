#include "Dog.hpp"

Dog::Dog(void): Animal(), _brain(new Brain())
{
	_type = "Dog";
	std::cout << "Dog spawn with default constructor." << std::endl;
}

Dog::Dog(const Dog& source): Animal(source), _brain(new Brain(*source._brain))
{
	std::cout << "Dog spawn with coppy constructor." << std::endl;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog despawn." << std::endl;
}

Dog&	Dog::operator=(const Dog& source)
{
	if (this != &source)
	{
		_type = "Dog";
		delete _brain;
		_brain = new Brain(*source._brain);
	}
	std::cout << "Dog spawn with coppy assignment oparetor." << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "hong hong" << std::endl;
}

Brain*	Dog::getBrain(void) const
{
	return (_brain);
}
