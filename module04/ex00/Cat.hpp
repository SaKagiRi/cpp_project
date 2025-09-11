#pragma once

#include "Animal.hpp"

class Cat: public Animal
{
	private:
	public:
		Cat(void);
		Cat(const Cat& source);

		virtual	~Cat(void);

		Cat& operator=(const Cat& source);

		void	makeSound(void) const;
};
