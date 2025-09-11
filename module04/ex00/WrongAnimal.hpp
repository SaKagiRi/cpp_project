#pragma once

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& source);

		virtual	~WrongAnimal(void);

		WrongAnimal&	operator=(const WrongAnimal& source);

		void	makeSound(void) const;
		std::string		getType(void) const;
};
