#pragma once

#include <iostream>
#include <sstream>

typedef enum
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	ERROR,
} e_type;

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& source);
		ScalarConverter& operator=(const ScalarConverter& source);
		~ScalarConverter(void);
	public:
		static void convert(const std::string &raw);
};
