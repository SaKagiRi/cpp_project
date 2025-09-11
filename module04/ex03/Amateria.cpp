#include "Amateria.hpp"

AMateria::AMateria(void): _type("void")
{
	std::cout << "AMateria default constructor called." << std::endl;
}
AMateria::AMateria(const std::string& type): _type(type)
{
	std::cout << "AMateria assign constructor called." << std::endl;
}

AMateria::AMateria(const AMateria& source): _type(source._type)
{
	std::cout << "AMateria coppy constructor called." << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called." << std::endl;
}

AMateria& AMateria::operator=(const AMateria& source)
{
	if (this != &source)
	{
		_type = source._type;
	}
	std::cout << "AMateria coppy assignment operator called." << std::endl;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "USE '" << _type << "' to " << target.getName() << std::endl;
}
