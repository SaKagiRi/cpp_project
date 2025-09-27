#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cwchar>

std::ostream&	operator<<(std::ostream& os, AForm& form)
{
	os << "AForm name: " << form.getName() << std::endl;
	os << "AForm signed: " << form.getSign() << std::endl;
	os << "AForm sign require: " << form.getGradeToSign() << std::endl;
	os << "AForm execute require: " << form.getGradetoExecute() << std::endl;
	return os;
}

//########################################################################

AForm::AForm(void): _name("AForm"), _issign(false), _gradeToSign(50), _gradeToExecute(25) {}
AForm::AForm(std::string name, int gradeToSign, int gradeToException): _name(name), _issign(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToException)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw(AForm::GradeTooHighException());
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw(AForm::GradeTooLowException());
}
AForm::AForm(const AForm& source): _name(source._name), _issign(source._issign), _gradeToSign(source._gradeToSign), _gradeToExecute(source._gradeToExecute) {}
AForm::~AForm(void) {}

AForm&	AForm::operator=(const AForm& source)
{
	if (this != &source)
	{
		_issign = source._issign;
	}
	return (*this);
}

//########################################################################

std::string		AForm::getName(void) const
{
	return _name;
}
bool			AForm::getSign(void) const
{
	return _issign;
}
int		AForm::getGradeToSign(void) const
{
	return _gradeToSign;
}
int		AForm::getGradetoExecute(void) const
{
	return _gradeToExecute;
}

void		AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw(AForm::GradeTooLowException());
	if (_issign)
		throw(AForm::AlreadySignedException());
	_issign = true;
}

void		AForm::execute(Bureaucrat const & executor) const
{
	if (!_issign)
		throw(AForm::FormNotSignException());
	if (executor.getGrade() > _gradeToExecute)
		throw(AForm::GradeTooLowException());
	action();
}

//########################################################################

const char*		AForm::GradeTooLowException::what(void) const throw()
{
	return ("AForm grade too low");
}

const char*		AForm::GradeTooHighException::what(void) const throw()
{
	return ("AForm grade too high");
}

const char*		AForm::AlreadySignedException::what(void) const throw()
{
	return ("AForm is already signed");
}

const char*		AForm::FormNotSignException::what(void) const throw()
{
	return ("AForm not sign");
}
