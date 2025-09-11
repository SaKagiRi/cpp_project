#pragma once

#include <iostream>

class Brain
{
	private:
		const static	int	_brain_cell = 100;
		std::string		_idea[_brain_cell];
	public:
		Brain(void);
		Brain(const Brain& source);

		~Brain(void);

		Brain&	operator=(const Brain& source);

		std::string	getBrain(int index) const;
		void		setBrain(int index, std::string idea);
};
