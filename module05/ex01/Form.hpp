#pragma once

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class Form
{
	private:
		const std::string	_name;
		bool				_issign;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
		Form(void);
		Form(std::string name, int gradeToSign, int gradeToException);
		Form(const Form& source);
		Form&	operator=(const Form& source);
		~Form(void);

		std::string			getName(void) const;
		bool				getSign(void) const;
		int			getGradeToSign(void) const;
		int			getGradetoExecute(void) const;
		void		beSigned(Bureaucrat& b);


		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};

		class AlreadySignedException: public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, Form& form);
