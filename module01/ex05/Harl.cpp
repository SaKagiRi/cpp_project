#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-\
triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << " cannot believe adding extra bacon costs more money. You didn’t put\
enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << " think I deserve to have some extra bacon for free. I’ve been coming for\
years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

/*
void	Harl::complain(std::string level)
{
	std::string		levels[] = {
					"DEBUG",
					"INFO",
					"WARNING",
					"ERROR"};
	void			(Harl::*func[])() = {
					&Harl::debug,
					&Harl::info,
					&Harl::warning,
					&Harl::error};
	bool			fn = false;

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*func[i])();
			fn = true;
		}
	}
	if (!fn)
		std::cout << "Error" << std::endl;
}
*/

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
			break ;
		case 1 :
			Harl::info();
			break ;
		case 2 :
			Harl::warning();
			break ;
		case 3 :
			Harl::error();
			break ;
	}
}
