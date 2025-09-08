#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	bob("somebody");
	ClapTrap	tob("someone");


	tob.beRepaired(9999);
	bob.attact(tob.getName());
	tob.takeDamage(10);
	tob.attact(bob.getName());
	bob.takeDamage(10);
	bob.attact(tob.getName());
}
