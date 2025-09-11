#pragma once

#include "ICharacter.hpp"

#ifndef MAX_MATERIA
# define MAX_MATERIA 4
#endif

class Character: public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[MAX_MATERIA];
	public:
		Character(void);
		Character(std::string name);
		Character(const Character& source);
		Character&	operator=(const Character& source);
		virtual ~Character(void);

		std::string	const & getName(void) const;
		AMateria*	getMateria(int idx) const;

		void		equip(AMateria* m);
		void		unequip(int idx);
		void		use(int idx, ICharacter& target);
};
