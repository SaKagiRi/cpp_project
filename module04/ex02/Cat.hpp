#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain*	_brain;
	public:
		Cat(void);
		Cat(const Cat& source);

		virtual	~Cat(void);

		Cat& operator=(const Cat& source);

		void	makeSound(void) const;
		Brain*	getBrain(void) const;
};
