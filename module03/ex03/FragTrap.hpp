#pragma once

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	private:
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& source);

		virtual ~FragTrap(void);

		FragTrap&	operator=(const FragTrap& source);

		void	highFivesGuys(void);
};
