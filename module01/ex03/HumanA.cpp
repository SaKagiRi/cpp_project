#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Weapon): name(name), weapon(Weapon)
{
	this->name = name;
	this->weapon = Weapon;
}

HumanA::~HumanA(void)
{
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon Weapon)
{
	this->weapon = Weapon;
}
