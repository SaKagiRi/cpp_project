#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {}
Intern::Intern(const Intern& source) {(void)source;}
Intern::~Intern(void) {}
Intern& Intern::operator=(const Intern& source)
{
	(void)source;
	return (*this);
}

AForm *Intern::CreateShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::CreateRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::CreatePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	std::string lst[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm* (Intern::*creators[3])(std::string) = {
            &Intern::CreateShrubberyCreationForm,
            &Intern::CreateRobotomyRequestForm,
            &Intern::CreatePresidentialPardonForm
    };

	for (int i = 0; i < 3; i++)
	{
		if (formName == lst[i])
		{
			std::cout << ("Create" + lst[i]) << ": " << target << std::endl;
			return (this->*creators[i])(target);
		}
	}
	throw(Intern::FormNameNotFound());
}

const char *Intern::FormNameNotFound::what(void) const throw()
{
	return ("Formname not match.");
}
