#include "HumanB.hpp"

HumanB::HumanB(std::string name): weapon(NULL)
{
	this->name = name;
}

HumanB::~HumanB(void)
{
}

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &Weapon)
{
	this->weapon = &Weapon;
}
