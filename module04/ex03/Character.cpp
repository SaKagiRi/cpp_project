#include "Character.hpp"
#include "Amateria.hpp"

Character::Character(void): _name("newbie")
{
	std::cout << "Character default constructor called." << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::Character(std::string name): _name(name)
{
	std::cout << "Character assign constructor called." << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::Character(const Character& source): _name(source._name)
{
	std::cout << "Character coppy constructor called." << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (source._inventory[i] != NULL)
			_inventory[i] = source._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character&	Character::operator=(const Character& source)
{
	std::cout << "Character coppy assignment operator called." << std::endl;
	if (this != &source)
	{
		_name = source._name;
		for (int i = 0; i < MAX_MATERIA; i++)
		{
			if (_inventory[i] != NULL)
				delete _inventory[i];
			if (source._inventory[i] != NULL)
				_inventory[i] = source._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
	std::cout << "Character destructor called." << std::endl;
}

std::string	const & Character::getName(void) const
{
	return (_name);
}

AMateria*	Character::getMateria(int idx) const
{
	return (_inventory[idx]);
}

void		Character::equip(AMateria* m)
{
	bool	success;

	success = false;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (!_inventory[i])
		{
			success = true;
			_inventory[i] = m->clone();
			std::cout << _name << " equip " << m->getType() << " on slot " << i << std::endl;
			break ;
		}
	}
	if (!success)
		std::cout << "Inventory is already full." << std::endl;
}

void		Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_MATERIA)
	{
		std::cout << "Not enough slot." << std::endl;
		return ;
	}
	if (!_inventory[idx])
	{
		std::cout << "This slot is empty." << std::endl;
		return ;
	}
	std::cout << _name << " unequip " << _inventory[idx]->getType() << " on slot " << idx << std::endl;
	delete _inventory[idx];
	_inventory[idx] = NULL;
}

void		Character::use(int idx, ICharacter& target)
{
	if (!_inventory[idx])
	{
		std::cout << "This slot is empty." << std::endl;
		return ;
	}
	std::cout << _name << " cast " << _inventory[idx]->getType() << " . . . " << std::endl;
	_inventory[idx]->use(target);
}
