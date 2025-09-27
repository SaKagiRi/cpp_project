#include "Form.hpp"

std::ostream&	operator<<(std::ostream& os, Form& form)
{
	os << "Form name: " << form.getName() << std::endl;
	os << "Form signed: " << form.getSign() << std::endl;
	os << "Form sign require: " << form.getGradeToSign() << std::endl;
	os << "Form execute require: " << form.getGradetoExecute() << std::endl;
	return os;
}

//########################################################################

Form::Form(void): _name("Form"), _issign(false), _gradeToSign(50), _gradeToExecute(25) {}
Form::Form(std::string name, int gradeToSign, int gradeToException): _name(name), _issign(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToException)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw(Form::GradeTooHighException());
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw(Form::GradeTooLowException());
}
Form::Form(const Form& source): _name(source._name), _issign(source._issign), _gradeToSign(source._gradeToSign), _gradeToExecute(source._gradeToExecute) {}
Form::~Form(void) {}

Form&	Form::operator=(const Form& source)
{
	if (this != &source)
	{
		_issign = source._issign;
	}
	return (*this);
}

//########################################################################

std::string		Form::getName(void) const
{
	return _name;
}
bool			Form::getSign(void) const
{
	return _issign;
}
int		Form::getGradeToSign(void) const
{
	return _gradeToSign;
}
int		Form::getGradetoExecute(void) const
{
	return _gradeToExecute;
}
void		Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw(Form::GradeTooLowException());
	if (_issign)
		throw(Form::AlreadySignedException());
	_issign = true;
}

//########################################################################

const char*		Form::GradeTooLowException::what(void) const throw()
{
	return ("Form grade too low");
}

const char*		Form::GradeTooHighException::what(void) const throw()
{
	return ("Form grade too high");
}

const char*		Form::AlreadySignedException::what(void) const throw()
{
	return ("Form is already signed");
}
