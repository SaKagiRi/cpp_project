#pragma once

#include "Amateria.hpp"

class Ice: public AMateria
{
	private:
	public:
		Ice(void);
		Ice(const Ice& source);
		Ice&	operator=(const Ice& source);
		~Ice(void);

		AMateria*	clone() const;
		void 		use(ICharacter& target);
};
