#include <iostream>
#include <cctype>

void	print(char	*str)
{
	while (*str)
		std::cout << (char)toupper(*str++);
}

void	upper_arg(char **arg)
{
	while (*arg)
		print(*arg++);
	std::cout << std::endl;
}

int	main(int c, char **v)
{
	if (c == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return (1);
	}
	upper_arg(&v[1]);
	return (0);
}
