#include "Harl.hpp"

int	main(int c, char **v)
{
	Harl	a;

	if (c != 2)
		return 0;
	a.complain(v[1]);
}
