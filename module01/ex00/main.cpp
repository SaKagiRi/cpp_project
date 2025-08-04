#include "Zombie.hpp"

int	main(void)
{
	Zombie	*coby;

	coby = newZombie("coby");
	randomChump("bob");

	coby->announce();
	delete coby;
}
