#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("unknow"), _hitPoint(10), _energy(10), _damage(10)
{
	std::cout << "ClapTrap call default constructor." << std::endl;
}


ClapTrap::ClapTrap(std::string name): _name(name), _hitPoint(10), _energy(10), _damage(10)
{
	std::cout << "ClapTrap call constructor with name: " << name << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hp, int mp, int atk): _name(name), _hitPoint(hp), _energy(mp), _damage(atk)
{
	std::cout << "Set stat ClapTrap constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& source)
{
	std::cout << "ClapTrap call coppy constructor." << std::endl;
	*this = source;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& source)
{
	if (this != &source)
	{
		_name = source._name;
		_hitPoint = source._hitPoint;
		_energy = source._energy;
		_damage = source._damage;
	}
	std::cout << "ClapTrap coppy assignment operator." << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap call destructor." << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoint <= 0)
	{
		std::cout << "ClapTrap " << _name << " can not attack, " << _name << " is death" << std::endl;
		return ;
	}
	if (_energy <= 0)
	{
		std::cout << "ClapTrap " << _name << " can not attack, " << _name << " not enough energy" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target \
		<< ", causing " << _damage << " points of damage!" << std::endl;
	_energy--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoint <= 0)
	{
		std::cout << "ClapTrap " << _name << " can not repaired, " << _name << " is death" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " take Damage " << amount << " point" << std::endl;
	if (_hitPoint <= (int)amount)
		std::cout << "ClapTrap " << _name << " is death" << std::endl;
	_hitPoint -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoint <= 0)
	{
		std::cout << "ClapTrap " << _name << " can not repaired, " << _name << " is death" << std::endl;
		return ;
	}
	if (_energy <= 0)
	{
		std::cout << "ClapTrap " << _name << " can not repaired, " << _name << " not enough energy" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " Repaired " << amount << " point" << std::endl;
	_hitPoint += amount;
	_energy--;
}

std::string		ClapTrap::getName(void) const
{
	return (_name);
}

void	ClapTrap::printStatus(void) const
{
	std::cout << "name: " << _name << std::endl;
	std::cout << "Hp: " << _hitPoint << std::endl;
	std::cout << "Mp: " << _energy << std::endl;
	std::cout << "Str: " << _damage << std::endl;
}
