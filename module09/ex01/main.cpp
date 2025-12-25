#include "RPN.hpp"

int main(int c, char **v)
{
	if (c != 2)
	{
		std::cout << "Usage: ./RPN <expr>" << std::endl;
		return (1);
	}
	try{
		std::string expr(v[1]);
		RPN::expr(expr);
	}
	catch(const std::exception& e)
	{
		return (1);
	}
	return (0);
}
