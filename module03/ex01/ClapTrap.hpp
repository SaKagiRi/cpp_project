#pragma once

#include <iostream>

class	ClapTrap {
	protected:
		std::string	_name;
		int			_hitPoint;
		int			_energy;
		int			_damage;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(std::string name, int hp, int mp, int str);
		ClapTrap(const ClapTrap& source);

		virtual ~ClapTrap(void);

		ClapTrap&	operator=(const ClapTrap& source);

		std::string		getName(void) const;
		void			printStatus(void) const;
		virtual void	attact(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};
