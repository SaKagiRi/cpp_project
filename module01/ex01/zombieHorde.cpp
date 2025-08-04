#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zom;

	zom = new Zombie[N];
	for (int i = 0; i < N; i++)
		zom[i].setName(name);
	return (zom);
}
