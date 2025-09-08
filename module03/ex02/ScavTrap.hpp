#pragma once

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:
		bool	_guardGate;
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& source);

		virtual ~ScavTrap(void);

		ScavTrap&	operator=(const ScavTrap& source);

		void	attact(const std::string& target);
		void	guardGate(void);
};
