#include "ClapTrap.hpp"
// #include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	a;
	FragTrap	b("bob");
	FragTrap	c(b);
	FragTrap	d = c;
	ClapTrap*	e = new FragTrap(b);
	const ClapTrap* f = new FragTrap(b);

	std::cout << std::endl;
	e->printStatus();
	f->printStatus();
	std::cout << std::endl;
	a.highFivesGuys();
	a.highFivesGuys();
	std::cout << std::endl;
	std::cout << "try a attack b" << std::endl;
	a.attact(b.getName());
	b.takeDamage(20);
	a.attact(b.getName());
	b.takeDamage(20);
	a.attact(b.getName());
	b.takeDamage(20);
	a.attact(b.getName());
	b.takeDamage(20);
	a.attact(b.getName());
	b.takeDamage(20);
	std::cout << std::endl;
	std::cout << "status:b is" << std::endl;
	b.printStatus();
	std::cout << std::endl;
	std::cout << "status:a is" << std::endl;
	a.printStatus();
	std::cout << std::endl;
	std::cout << "try use B attack" << std::endl;
	b.attact(a.getName());
	std::cout << std::endl;

	delete e;
	delete f;
}
