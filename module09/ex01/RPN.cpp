#include "RPN.hpp"
#include <stdexcept>

std::stack<int> RPN::_stack;

// private member function
void RPN::validateValue(std::string expr)
{
	size_t count_digit = 0;
	size_t count_op = 0;

	for (size_t i = 0; i < expr.length(); i++)
	{
		if (i % 2 != 0 && expr.at(i) != ' ')
			throw std::runtime_error(ERR_EXPR_FORMAT);
		if (i % 2 != 0)
			continue ;
		if (expr.at(i) >= '0' && expr.at(i) <= '9')
			count_digit++;
		else if (expr.at(i) == '+' || expr.at(i) == '-' ||
			expr.at(i) == '*' || expr.at(i) == '/')
		{
			count_op++;
			if (count_op > count_digit - 1)
			{
				std::stringstream ss;
				ss << expr.at(i);
				throw std::runtime_error(ERR_EXPR_INVALID" '" + ss.str() + "'");
			}
		}
		else
			throw std::runtime_error(ERR_EXPR_NOT_NUM_AND_OP);
	}
	if (count_digit - 1 != count_op)
	{
		std::stringstream ss;
		ss << (count_digit - 1) - count_op;
		throw std::runtime_error("need more opearator :" + ss.str());
	}
}

// member function

int RPN::expr(std::string expression)
{
	try{
		// std::stringstream iss;
		while (!_stack.empty())
			_stack.pop();
		validateValue(expression);
		for (size_t i = 0; i < expression.length(); i++)
		{
			if (expression.at(i) >= '0' && expression.at(i) <= '9')
				_stack.push(expression.at(i) - '0');
			else if (expression.at(i) == ' ')
				continue ;
			else
			{
				int sum, a, b;
				b = _stack.top();
				_stack.pop();
				a = _stack.top();
				_stack.pop();
				switch(expression.at(i)){
					case '+':
						sum = a + b;
						break ;
					case '-':
						sum = a - b;
						break ;
					case '*':
						sum = a * b;
						break ;
					case '/':
						if (b == 0)
							throw std::runtime_error("Division by zero.");
						sum = a / b;
						break ;
				}
				_stack.push(sum);
				// std::cout << expression.at(i) << std::endl;
			}
		}
		std::cout << _stack.top() << std::endl;

	}catch (const std::exception& e)
	{
		std::cerr << "expr error: " << e.what() << std::endl;
		throw(e);
	}
	return (1);
}
