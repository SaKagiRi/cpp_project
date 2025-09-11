#pragma once

#include "Amateria.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria*	_scroll[MAX_MATERIA];
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& source);
		MateriaSource& operator=(const MateriaSource& source);
		~MateriaSource(void);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};
