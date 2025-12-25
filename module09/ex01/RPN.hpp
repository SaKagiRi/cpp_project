#ifndef RPN_H
# define RPN_H

# include <iostream>
# include <sstream>
# include <stack>
# include <exception>

// errorMsg
# define ERR_EXPR_FORMAT "format must separate by one space."
# define ERR_EXPR_NOT_NUM_AND_OP "expr must have only one digit number and operator '+' '-' '*' '/'"
# define ERR_EXPR_INVALID "The expression is invalid."

class RPN
{
	private:
		static std::stack<int> _stack;

		RPN(void);
		~RPN(void);
		RPN(const RPN&);
		RPN operator=(const RPN&);

		static void validateValue(std::string);

	public:
		static int expr(std::string);
};

#endif
