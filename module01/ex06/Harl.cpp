#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-\
triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << " cannot believe adding extra bacon costs more money. You didn’t put\
enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << " think I deserve to have some extra bacon for free. I’ve been coming for\
years, whereas you started working here just last month." << std::endl << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string		levels[] = {
					"DEBUG",
					"INFO",
					"WARNING",
					"ERROR"};
	int				fn = -1;

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			fn = i;
			break ;
		}
	}

	switch (fn)
	{
		case -1:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
		case 0 :
			Harl::debug();
		case 1 :
			Harl::info();
		case 2 :
			Harl::warning();
		case 3 :
			Harl::error();
	}
}
