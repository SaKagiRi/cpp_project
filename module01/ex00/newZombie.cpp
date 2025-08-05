#include "Zombie.hpp"

Zombie	*newZombie( std::string name )
{
	Zombie	*z;

	z = new Zombie(name);
	if (!z)
	{
		std::cout << "new zombie not success" << std::endl;
		return (NULL);
	}
	return (z);
}
