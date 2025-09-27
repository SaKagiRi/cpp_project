#include "Bureaucrat.hpp"

void	head(std::string head)
{
	int len = head.length();
	int format = 50 - len;

	std::cout << "\n\033[1;35m";
	for (int i = 0; i <= format / 2; i++)
	{
	  std::cout << "/";
	}
	std::cout << " " << head << " ";
	for (int i = 0; i <= format / 2; i++)
	{
	  std::cout << "/";
	}
	std::cout << "\033[0m" << std::endl;
}

int	main(void)
{

	head("Try to decretement grade");
	try 
	{
		Bureaucrat	a("people", 50);
		std::cout << a << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("Try to incretement grade");
	try 
	{
		Bureaucrat	a("people", 50);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("Try to incretement grade 1");
	try 
	{
		Bureaucrat	b("idontknow", 1);
		std::cout << b << std::endl;
		b.incrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("Try to decretement grade 150");
	try 
	{
		Bureaucrat	b("idontknow", 150);
		std::cout << b << std::endl;
		b.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("Try to create bureaucrat grade 0");
	try 
	{
		Bureaucrat	b("idontknow", 0);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("Try to create bureaucrat grade 151");
	try 
	{
		Bureaucrat	b("idontknow", 151);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}
