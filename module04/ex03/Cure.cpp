#include "Cure.hpp"
#include "Amateria.hpp"

Cure::Cure(void): AMateria("Cure")
{
	std::cout << "Cure default constructor called." << std::endl;
}

Cure::Cure(const Cure& source): AMateria(source)
{
	std::cout << "Cure coppy constructor called." << std::endl;
}

Cure&	Cure::operator=(const Cure& source)
{
	if (this != &source)
	{
		_type = source._type;
	}
	std::cout << "Cure coppy assignment operator called." << std::endl;
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called." << std::endl;
}

AMateria*	Cure::clone() const
{
	return (new Cure());
}

void 		Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
