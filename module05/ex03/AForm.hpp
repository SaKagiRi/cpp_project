#pragma once

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class AForm
{
	private:
		const std::string	_name;
		bool				_issign;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
		AForm(void);
		AForm(std::string name, int gradeToSign, int gradeToException);
		AForm(const AForm& source);
		AForm&	operator=(const AForm& source);
		virtual ~AForm(void);

		std::string			getName(void) const;
		bool				getSign(void) const;
		int			getGradeToSign(void) const;
		int			getGradetoExecute(void) const;
		void		beSigned(Bureaucrat& b);
		void		execute(Bureaucrat const & executor) const;

		virtual void		action(void) const =0;


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

		class FormNotSignException: public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};

};

std::ostream&	operator<<(std::ostream& os, AForm& form);
