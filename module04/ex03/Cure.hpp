#pragma once

#include "Amateria.hpp"

class Cure: public AMateria
{
	private:
	public:
		Cure(void);
		Cure(const Cure& source);
		Cure&	operator=(const Cure& source);
		~Cure(void);

		AMateria*	clone() const;
		void 		use(ICharacter& target);
};
