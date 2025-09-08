#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	a;
	DiamondTrap	b("bob");
	DiamondTrap	c(b);
	DiamondTrap	d = c;
	ClapTrap*	e = new DiamondTrap(b);
	const ClapTrap* f = new DiamondTrap(b);

	std::cout << std::endl;
	// e->whoAmI();  -- ClapTrapไม่รู้จัก ไม่สามารถเรียกใช้ผ่านVirtual Tableได้
	// f->whoAmI();
	e->printStatus();
	std::cout << std::endl;
	f->printStatus();
	std::cout << std::endl;
	a.whoAmI();
	std::cout << std::endl;
	a.highFivesGuys();
	a.highFivesGuys();
	a.guardGate();
	a.guardGate();
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
	b.whoAmI();
	std::cout << std::endl;
	a.whoAmI();
	std::cout << std::endl;
	std::cout << "try use B attack" << std::endl;
	b.attact(a.getName());
	std::cout << std::endl;

	delete e;
	delete f;
}
