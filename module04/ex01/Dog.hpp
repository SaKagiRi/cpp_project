#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain*	_brain;
	public:
		Dog(void);
		Dog(const Dog& source);

		virtual	~Dog(void);

		Dog& operator=(const Dog& source);

		void	makeSound(void) const;
		Brain*	getBrain(void) const;
};
