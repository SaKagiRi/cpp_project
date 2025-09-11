#include "MateriaSource.hpp"
#include "Character.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		_scroll[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& source)
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (source._scroll[i] != NULL)
			_scroll[i] = source._scroll[i]->clone();
		else
			_scroll[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& source)
{
	if (this != &source)
	{
		for (int i = 0; i < MAX_MATERIA; i++)
		{
			if (_scroll[i] != NULL)
				delete _scroll[i];
			if (source._scroll[i] != NULL)
				_scroll[i] = source._scroll[i]->clone();
			else
				_scroll[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (_scroll[i] != NULL)
			delete _scroll[i];
	}
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (_scroll[i] && _scroll[i]->getType() == m->getType())
		{
			std::cout << "This materia '" << _scroll[i]->getType() << "' already have in this source." << std::endl;
			return ;
		}
	}
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (_scroll[i] == NULL)
		{
			_scroll[i] = m;
			std::cout << "learning " << m->getType()  << " . . ." << std::endl;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0;i < MAX_MATERIA; i++)
	{
		if (_scroll[i] && _scroll[i]->getType() == type)
		{
			return (_scroll[i]->clone());
		}
	}
	std::cout << "Not have " << type << " in this source." << std::endl;
	return (NULL);
}
