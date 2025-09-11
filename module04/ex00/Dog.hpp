#pragma once

#include "Animal.hpp"

class Dog: public Animal
{
	private:
	public:
		Dog(void);
		Dog(const Dog& source);

		virtual	~Dog(void);

		Dog& operator=(const Dog& source);

		void	makeSound(void) const;
};
