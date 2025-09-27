#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	head("Try to create correctly");
	try 
	{
		Form a("Form", 150, 150);
		std::cout << a;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("Try to create form exec grade too low (151)");
	try 
	{
		Form a("Form", 150, 151);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("Try to create form exec grade too high (0)");
	try 
	{
		Form a("Form", 150, 0);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("Try to create form sign grade too low (151)");
	try 
	{
		Form a("Form", 151, 150);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("Try to create form sign grade too high (0)");
	try 
	{
		Form a("Form", 0, 150);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("Try to sign correctly");
	try 
	{
		Bureaucrat	b("people", 50);
		Form a("Form", 60, 150);
		std::cout << b << std::endl;
		std::cout << a;
		std::cout << "\nsign . . . \n\n";
		b.signForm(a);
		std::cout << a;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("Try to sign grade too low");
	try 
	{
		Bureaucrat	b("people", 70);
		Form a("Form", 60, 150);
		std::cout << b << std::endl;
		std::cout << a;
		std::cout << "\nsign . . . \n\n";
		b.signForm(a);
		std::cout << a;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("Try to sign it again");
	try 
	{
		Bureaucrat	b("people", 50);
		Form a("Form", 60, 150);
		std::cout << b << std::endl;
		std::cout << a;
		std::cout << "\nsign . . . \n\n";
		b.signForm(a);
		std::cout << a;
		std::cout << "\nsign . . . \n\n";
		b.signForm(a);
		std::cout << a;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}
