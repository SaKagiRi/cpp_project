#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreateForm", 145, 137), _target("default") {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreateForm", 145, 137), _target(target) {}
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& source): AForm(source), _target(source._target) {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& source)
{
	if (this != &source)
	{
		_target = source._target;
	}
	return (*this);
}

void ShrubberyCreationForm::action(void) const
{
	std::fstream output;

	output.exceptions(std::fstream::failbit | std::fstream::badbit);
	output.open((_target + "_shrubbery").c_str(), std::ios::in | std::ios::out | std::ios::app);
	output << "                                               |" << std::endl
	 << "                                              -x-" << std::endl
	 << "                                               |" << std::endl
	 << "              v .   ._, |_  .," << std::endl
	 << "           `-._\\/  .  \\ /    |/_" << std::endl
	 << "               \\\\  _\\, y | \\//" << std::endl
	 << "         _\\_.___\\\\, \\\\/ -.\\||" << std::endl
	 << "           `7-,--.`._||  / / ," << std::endl
	 << "           /'     `-. `./ / |/_.'" << std::endl
	 << "                     |    |/\\/" << std::endl
	 << "                     |_    /" << std::endl
	 << "                     |-   |" << std::endl
	 << "                     |   =|" << std::endl
	 << "                     |    |" << std::endl
	 << "--------------------/ ,  . \\--------._" << std::endl;
	std::cout << "Successfully planted a " << _target << "_shrubbery." << std::endl;
	output.close();
}

void	ShrubberyCreationForm::setTarget(std::string target)
{
	_target = target;
}
std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}
