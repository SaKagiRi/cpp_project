#include "Bureaucrat.hpp"

std::ostream&	operator<<(std::ostream& os, Bureaucrat& source)
{
	os << source.getName() << ", bureaucrat grade " << source.getGrade();
	return (os);
}

//########################################################################

Bureaucrat::Bureaucrat(void): _name("people"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& source): _name(source._name), _grade(source._grade) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& source)
{
	if (this != &source)
	{
		_name = source._name;
		_grade = source._grade;
	}
	return (*this);
}

//########################################################################

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (_grade);
}

//########################################################################

void	Bureaucrat::incrementGrade(void)
{
	if (_grade == 1)
		throw(Bureaucrat::GradeTooHighException());
	_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade == 150)
		throw(Bureaucrat::GradeTooLowException());
	_grade++;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too Hight");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too Low");
}

//########################################################################
