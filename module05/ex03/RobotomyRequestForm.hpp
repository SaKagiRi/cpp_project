#pragma once

#include "AForm.hpp"
#include <stdlib.h>

class RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		virtual ~RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm& source);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& source);

		virtual void action(void) const;

		void	setTarget(std::string target);
		std::string	getTarget(void) const;

		class RobotizationFailed: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
