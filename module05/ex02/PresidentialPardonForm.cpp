#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5), _target("default") {}
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target) {}
PresidentialPardonForm::~PresidentialPardonForm(void) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& source): AForm(source), _target(source._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& source)
{
	if (this != &source)
	{
		_target = source._target;
	}
	return (*this);
}

void PresidentialPardonForm::action(void) const
{
	std::cout << _target << " has been pardoned." << std::endl;
}

void	PresidentialPardonForm::setTarget(std::string target)
{
	_target = target;
}
std::string	PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}
