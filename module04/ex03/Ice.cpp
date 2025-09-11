#include "Ice.hpp"
#include "Amateria.hpp"

Ice::Ice(void): AMateria("Ice")
{
	std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice(const Ice& source): AMateria(source)
{
	std::cout << "Ice coppy constructor called." << std::endl;
}

Ice&	Ice::operator=(const Ice& source)
{
	if (this != &source)
	{
		_type = source._type;
	}
	std::cout << "Ice coppy assignment operator called." << std::endl;
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called." << std::endl;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
	return (new Ice());
}
