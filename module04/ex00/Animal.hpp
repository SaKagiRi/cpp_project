#pragma once

#include <iostream>

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal(void);
		Animal(const Animal& source);

		virtual	~Animal(void);

		Animal&	operator=(const Animal& source);

		virtual	void	makeSound(void) const;
		std::string		getType(void) const;
};
