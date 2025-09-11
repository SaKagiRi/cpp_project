#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default construtor called." << std::endl;
}

Brain::Brain(const Brain& source)
{
	std::cout << "Brain coppy constructor called." << std::endl;
	*this = source;
}

Brain&	Brain::operator=(const Brain& source)
{
	for (int i = 0; i < _brain_cell; i++)
		_idea[i] = source._idea[i];
	std::cout << "Brain coppy assignment operator called." << std::endl;
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setBrain(int index, std::string idea)
{
	if (index < 0 || index >= _brain_cell)
	{
		std::cout << "idea out of range" << std::endl;
		return ;
	}
	_idea[index] = idea;
}

std::string	Brain::getBrain(int index) const
{
	if (index < 0 || index >= _brain_cell)
	{
		std::cout << "idea out of range" << std::endl;
		return ("");
	}
	return (_idea[index]);
}
