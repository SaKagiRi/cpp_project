#pragma once

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& source);

		~DiamondTrap(void);

		DiamondTrap&	operator=(const DiamondTrap& source);

		void	attact(const std::string& target);
		void	whoAmI(void);
};
