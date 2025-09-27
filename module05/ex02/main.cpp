#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>

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

void	test_Shrubbery(void)
{
	head("Shrubbery can't sign");
	try
	{
		ShrubberyCreationForm oak;
		Bureaucrat p("me", 150);

		std::cout << "\033[1;32m""signing . . .""\033[0m" << std::endl;
		oak.beSigned(p);
		std::cout << "\033[1;31m""==signed==""\033[0m" << std::endl;

		std::cout << "\033[1;32m""executing . . .""\033[0m" << std::endl;
		oak.execute(p);
		std::cout << "\033[1;31m""==executed==""\033[0m" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("Shrubbery can sign but can't execute");
	try
	{
		ShrubberyCreationForm oak;
		Bureaucrat p("me", 145);

		std::cout << "\033[1;32m""signing . . .""\033[0m" << std::endl;
		oak.beSigned(p);
		std::cout << "\033[1;31m""==signed==""\033[0m" << std::endl;

		std::cout << "\033[1;32m""executing . . .""\033[0m" << std::endl;
		oak.execute(p);
		std::cout << "\033[1;31m""==executed==""\033[0m" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("Shrubbery try to execute but not sign");
	try
	{
		ShrubberyCreationForm oak;
		Bureaucrat p("me", 137);

		// std::cout << "\033[1;32m""signing . . .""\033[0m" << std::endl;
		// oak.beSigned(p);
		// std::cout << "\033[1;31m""==signed==""\033[0m" << std::endl;

		std::cout << "\033[1;32m""executing . . .""\033[0m" << std::endl;
		oak.execute(p);
		std::cout << "\033[1;31m""==executed==""\033[0m" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("Shrubbery can sign and execute but permission");
	try
	{
		ShrubberyCreationForm oak;
		Bureaucrat p("me", 137);

		system("touch default_shrubbery && chmod -rw default_shrubbery");
		std::cout << "\033[1;32m""signing . . .""\033[0m" << std::endl;
		oak.beSigned(p);
		std::cout << "\033[1;31m""==signed==""\033[0m" << std::endl;

		std::cout << "\033[1;32m""executing . . .""\033[0m" << std::endl;
		oak.execute(p);
		std::cout << "\033[1;31m""==executed==""\033[0m" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		system("rm -rf default_shrubbery");
	}

	head("Shrubbery correctly usage");
	try
	{
		ShrubberyCreationForm oak;
		Bureaucrat p("me", 137);

		std::cout << "\033[1;32m""signing . . .""\033[0m" << std::endl;
		oak.beSigned(p);
		std::cout << "\033[1;31m""==signed==""\033[0m" << std::endl;

		std::cout << "\033[1;32m""executing . . .""\033[0m" << std::endl;
		oak.execute(p);
		std::cout << "\033[1;31m""==executed==""\033[0m" << std::endl;
		std::cout << "cat file: " << oak.getName() << "_shrubbery" << std::endl;
		system("cat default_shrubbery");
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

}

void	test_Robot(void)
{
	head("Robotomy can't sign");
	try
	{
		RobotomyRequestForm robot;
		Bureaucrat p("me", 73);

		std::cout << "\033[1;32m""signing . . .""\033[0m" << std::endl;
		robot.beSigned(p);
		std::cout << "\033[1;31m""==signed==""\033[0m" << std::endl;

		std::cout << "\033[1;32m""executing . . .""\033[0m" << std::endl;
		robot.execute(p);
		std::cout << "\033[1;31m""==executed==""\033[0m" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("Robotomy can sign but can't execute");
	try
	{
		RobotomyRequestForm robot;
		Bureaucrat p("me", 72);

		std::cout << "\033[1;32m""signing . . .""\033[0m" << std::endl;
		robot.beSigned(p);
		std::cout << "\033[1;31m""==signed==""\033[0m" << std::endl;

		std::cout << "\033[1;32m""executing . . .""\033[0m" << std::endl;
		robot.execute(p);
		std::cout << "\033[1;31m""==executed==""\033[0m" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("Robotomy try to execute but not sign");
	try
	{
		RobotomyRequestForm robot;
		Bureaucrat p("me", 45);

		// std::cout << "\033[1;32m""signing . . .""\033[0m" << std::endl;
		// robot.beSigned(p);
		// std::cout << "\033[1;31m""==signed==""\033[0m" << std::endl;
		//
		std::cout << "\033[1;32m""executing . . .""\033[0m" << std::endl;
		robot.execute(p);
		std::cout << "\033[1;31m""==executed==""\033[0m" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("Robotomy correctly usage (10 times)");
	try
	{
		RobotomyRequestForm robot;
		Bureaucrat p("me", 45);

		std::cout << "\033[1;32m""signing . . .""\033[0m" << std::endl;
		robot.beSigned(p);
		std::cout << "\033[1;31m""==signed==""\033[0m" << std::endl;

		std::cout << "\033[1;32m""executing . . .""\033[0m" << std::endl;
		for (int i = 0; i < 10; i++)
		{
			try {
				robot.execute(p);
			} catch (const std::exception& e) {
				std::cout << "Error at iteration " << i+1 << ": " << e.what() << std::endl;
			}
		}
		std::cout << "\033[1;31m""==executed==""\033[0m" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

}

void	test_President(void)
{
	head("President can't sign");
	try
	{
		PresidentialPardonForm robot;
		Bureaucrat p("me", 26);

		std::cout << "\033[1;32m""signing . . .""\033[0m" << std::endl;
		robot.beSigned(p);
		std::cout << "\033[1;31m""==signed==""\033[0m" << std::endl;

		std::cout << "\033[1;32m""executing . . .""\033[0m" << std::endl;
		robot.execute(p);
		std::cout << "\033[1;31m""==executed==""\033[0m" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("President can sign but can't execute");
	try
	{
		PresidentialPardonForm robot;
		Bureaucrat p("me", 25);

		std::cout << "\033[1;32m""signing . . .""\033[0m" << std::endl;
		robot.beSigned(p);
		std::cout << "\033[1;31m""==signed==""\033[0m" << std::endl;

		std::cout << "\033[1;32m""executing . . .""\033[0m" << std::endl;
		robot.execute(p);
		std::cout << "\033[1;31m""==executed==""\033[0m" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("President try to execute but not sign");
	try
	{
		PresidentialPardonForm robot;
		Bureaucrat p("me", 5);

		// std::cout << "\033[1;32m""signing . . .""\033[0m" << std::endl;
		// robot.beSigned(p);
		// std::cout << "\033[1;31m""==signed==""\033[0m" << std::endl;
		//
		std::cout << "\033[1;32m""executing . . .""\033[0m" << std::endl;
		robot.execute(p);
		std::cout << "\033[1;31m""==executed==""\033[0m" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	head("President correctly usage");
	try
	{
		PresidentialPardonForm robot;
		Bureaucrat p("me", 5);

		std::cout << "\033[1;32m""signing . . .""\033[0m" << std::endl;
		robot.beSigned(p);
		std::cout << "\033[1;31m""==signed==""\033[0m" << std::endl;

		std::cout << "\033[1;32m""executing . . .""\033[0m" << std::endl;
		robot.execute(p);
		std::cout << "\033[1;31m""==executed==""\033[0m" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

}

int	main(void)
{
	std::cout << "=======================================================" << std::endl;
	std::cout << "Test shrubbery" << std::endl;
	std::cout << "=======================================================" << std::endl;
	test_Shrubbery();
	std::cout << "=======================================================" << std::endl;

	std::cout << std::endl;

	srand(time(NULL));
	std::cout << "=======================================================" << std::endl;
	std::cout << "Test robotomy" << std::endl;
	std::cout << "=======================================================" << std::endl;
	test_Robot();
	std::cout << "=======================================================" << std::endl;

	std::cout << std::endl;

	std::cout << "=======================================================" << std::endl;
	std::cout << "Test President" << std::endl;
	std::cout << "=======================================================" << std::endl;
	test_President();
	std::cout << "=======================================================" << std::endl;
}
