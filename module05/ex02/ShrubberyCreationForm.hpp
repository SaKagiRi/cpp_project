#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm& source);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& source);

		virtual void action(void) const;

		void	setTarget(std::string target);
		std::string	getTarget(void) const;
};
