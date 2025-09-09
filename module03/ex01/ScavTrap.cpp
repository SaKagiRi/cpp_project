#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	_hitPoint = 100;
	_energy = 50;
	_damage = 20;
	_guardGate = false;
	std::cout << "ScavTrap call Defualt constructor " << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	_hitPoint = 100;
	_energy = 50;
	_damage = 20;
	_guardGate = false;
	std::cout << "ScavTrap call constructor Name: " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& source): ClapTrap(source)
{
	_guardGate = source._guardGate;
	std::cout << "ScavTrap call coppy constructor" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap call Destructor" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& source)
{
	if (this != &source)
	{
		_damage = source._damage;
		_energy = source._energy;
		_hitPoint = source._hitPoint;
		_name = source._name;
		_guardGate = source._guardGate;
	}
	std::cout << "ScavTrap call coppy assignment operator" << std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoint <= 0)
	{
		std::cout << "ScavTrap " << _name << " can not attack, " << _name << " is death" << std::endl;
		return ;
	}
	if (_energy <= 0)
	{
		std::cout << "ScavTrap " << _name << " can not attack, " << _name << " not enough energy" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target \
		<< ", causing " << _damage << " points of damage!" << std::endl;
	_energy--;
}

void	ScavTrap::guardGate(void)
{
	if (_hitPoint <= 0)
	{
		std::cout << "no HP." << std::endl;
	}
	if (_guardGate == false)
	{
		_guardGate = true;
		std::cout << "is now in Gate keeper mode." << std::endl;
		return ;
	}
	std::cout << "it's already in Gate keeper mode." << std::endl;
}
