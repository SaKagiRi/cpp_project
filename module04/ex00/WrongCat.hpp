#pragma once

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	private:
	public:
		WrongCat(void);
		WrongCat(const WrongCat& source);

		virtual	~WrongCat(void);

		WrongCat& operator=(const WrongCat& source);

		void	makeSound(void) const;
};
