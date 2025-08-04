#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zom;
	int		N;

	N = 100;
	zom = zombieHorde(N, "kita");
	for (int i = 0; i < N; i++)
		zom[i].announce();
	delete[] zom;
}
