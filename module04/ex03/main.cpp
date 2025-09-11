#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Amateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

void	header(std::string head, std::string color)
{
	std::cout  << color << "////////// " << head << " //////////" << std::endl;
}

void	end(void)
{
	std::cout << "//////////////////////////////////////\033[0m" << std::endl << std::endl;
}

void	testCharacter(void)
{
	Character	a;
	Character	b("bob");
	AMateria*	ice = new Ice();

	std::cout << std::endl;
	header("Test Inventory", "\033[1;36m");
	a.equip(ice);
	a.equip(ice);
	a.equip(ice);
	a.equip(ice);
	a.equip(ice);
	end();

	header("Test Use Materia", "\033[1;31m");
	a.use(0, b);
	b.use(0, a);
	end();

	header("Coppy Character", "\033[1;32m");
	Character	c(a);
	end();

	header("Unequip All", "\033[1;33m");
	c.unequip(-1);
	c.unequip(4);
	c.unequip(3);
	c.unequip(2);
	c.unequip(1);
	c.unequip(0);
	end();

	delete ice;
}

void	testScroll(void)
{
	MateriaSource	scroll;
	AMateria*		ice = new Ice();
	AMateria*		cure = new Cure();

	header("Add Materia to Scroll", "\033[1;36m");
	scroll.learnMateria(ice);
	scroll.learnMateria(cure);
	scroll.learnMateria(cure);
	end();

	header("Create to new Materia", "\033[1;33m");
	AMateria*	newIce = scroll.createMateria("Ice");
	AMateria*	newCure= scroll.createMateria("Cure");
	AMateria*	newUnknow= scroll.createMateria("haha");
	end();

	delete newIce;
	delete newCure;
	delete newUnknow;
}

int	main(void)
{
	// {
	// 	Character	me("bob");
	// 	AMateria*	ice = new Ice();
	// 	AMateria*	coppy = ice->clone();
	//
	// 	std::cout << me.getName() << std::endl;
	// 	ice->use(me);
	// 	coppy->use(me);
	//
	// 	me.equip(ice);
	//
	// 	me.use(0, me);
	//
	//
	// 	delete coppy;
	// 	delete ice;
	// }

	std::cout << std::endl;

	{
		testCharacter();
		testScroll();
	}
}
