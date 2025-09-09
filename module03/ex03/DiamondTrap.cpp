#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"


DiamondTrap::DiamondTrap(void): ClapTrap("unknow_clap_name"), _name("unknow")
{
	_hitPoint = FragTrap::_hitPoint;
	_energy = 50;
	_damage = FragTrap::_damage;
	std::cout << "DiamondTrap call default constructor." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), _name(name)
{
	_hitPoint = FragTrap::_hitPoint;
	_energy = 50;
	_damage = FragTrap::_damage;
	std::cout << "DiamondTrap call constructor with name: " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& source): ClapTrap(source), ScavTrap(source), FragTrap(source), _name(source._name)
{
	std::cout << "DiamondTrap call coppy constructor." << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap call donstructor." << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& source)
{
	if (this != &source)
	{
		_name = source._name;
		_hitPoint = source._hitPoint;
		_energy = source._energy;
		_damage = source._damage;
	}
	std::cout << "DiamondTrap call coppy assignment oparetor." << std::endl;
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Hello I am a DiamondTrap name: " << _name << std::endl << "ClapTrap Status is:" << std::endl;
	printStatus();
	std::cout << "debug :" << _hitPoint << ", " << _energy << ", " << _damage << std::endl;
}
