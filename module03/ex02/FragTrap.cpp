#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	_hitPoint = 100;
	_damage = 30;
	_energy = 100;
	std::cout << "FragTrap call default constructor." << std::endl;
};

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	_hitPoint = 100;
	_damage = 30;
	_energy = 100;
	std::cout << "FragTrap call constructor with name: " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& source): ClapTrap(source)
{
	std::cout << "FragTrap call coppy constructor." << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& source)
{
	if (this != &source)
	{
		_name = source._name;
		_hitPoint = source._hitPoint;
		_energy = source._energy;
		_damage = source._damage;
	}
	std::cout << "FragTrap call coppy assignment oparetor." << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap call destructor" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (_hitPoint <= 0)
	{
		std::cout << "no HP." << std::endl;
	}
	std::cout << "FragTrap bob requests a positive high five! ✋" << std::endl;
}
