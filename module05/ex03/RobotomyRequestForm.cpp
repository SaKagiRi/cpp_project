#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45), _target("default") {}
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target) {}
RobotomyRequestForm::~RobotomyRequestForm(void) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& source): AForm(source), _target(source._target) {}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& source)
{
	if (this != &source)
	{
		_target = source._target;
	}
	return (*this);
}

void RobotomyRequestForm::action(void) const
{
	if (rand() % 2 == 1)
		std::cout << "Beeep Be Be Beeeee Beeeeeeeep. " << _target << " has been robotomized successfully!" << std::endl;
	else
		throw(RobotizationFailed());
}

const char *RobotomyRequestForm::RobotizationFailed::what(void) const throw()
{
	return ("Unfortunately robotomy failed.");
}

void	RobotomyRequestForm::setTarget(std::string target)
{
	_target = target;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}
