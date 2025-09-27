#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string		_target;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm& source);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& source);

		virtual void action(void) const;

		void	setTarget(std::string target);
		std::string	getTarget(void) const;
};
