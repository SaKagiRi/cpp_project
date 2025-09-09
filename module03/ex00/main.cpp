#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	bob("somebody");
	ClapTrap	tob("someone");


	tob.beRepaired(9999);
	bob.attack(tob.getName());
	tob.takeDamage(10);
	tob.attack(bob.getName());
	bob.takeDamage(10);
	bob.attack(tob.getName());
}
