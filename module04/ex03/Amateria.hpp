#pragma once

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string		_type;
	public:
		AMateria(void);
		AMateria(const std::string& source);
		AMateria(const AMateria& source);

		virtual ~AMateria(void);

		AMateria& operator=(const AMateria& source);

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
