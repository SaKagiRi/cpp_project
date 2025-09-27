#pragma once

#include "AForm.hpp"
#include <exception>

class Intern
{
	private:
	public:
		Intern(void);
		Intern(const Intern& source);
		~Intern(void);
		Intern& operator=(const Intern& source);

		AForm*	makeForm(std::string formName, std::string target);
		AForm *CreateShrubberyCreationForm(std::string target);
		AForm *CreateRobotomyRequestForm(std::string target);
		AForm *CreatePresidentialPardonForm(std::string target);

		class FormNameNotFound: public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
};
