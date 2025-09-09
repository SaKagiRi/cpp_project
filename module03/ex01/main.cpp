#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	a;
	ScavTrap	b("bob");
	ScavTrap	c(b);
	ScavTrap	d = c;
	ClapTrap*	e = new ScavTrap(b);
	const ClapTrap* f = new ScavTrap(b);

	std::cout << std::endl;
	e->printStatus();
	f->printStatus();
	std::cout << std::endl;
	a.guardGate();
	a.guardGate();
	std::cout << std::endl;
	std::cout << "try a attack b" << std::endl;
	a.attack(b.getName());
	b.takeDamage(20);
	a.attack(b.getName());
	b.takeDamage(20);
	a.attack(b.getName());
	b.takeDamage(20);
	a.attack(b.getName());
	b.takeDamage(20);
	a.attack(b.getName());
	b.takeDamage(20);
	std::cout << std::endl;
	std::cout << "status:b is" << std::endl;
	b.printStatus();
	std::cout << std::endl;
	std::cout << "status:a is" << std::endl;
	a.printStatus();
	std::cout << std::endl;
	std::cout << "try use B attack" << std::endl;
	b.attack(a.getName());
	std::cout << std::endl;

	delete e;
	delete f;
}
