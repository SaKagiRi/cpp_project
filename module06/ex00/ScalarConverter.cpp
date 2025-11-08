#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <iomanip>

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &source) {
  (void)source;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &source) {
  (void)source;
  return (*this);
}

//-------------------------------------------------------------------------
//                               Check Type                               //
//-------------------------------------------------------------------------

bool checkChar(const std::string &raw) {
  if (raw.length() == 1)
    return (true);
  return (false);
}

e_type checkNumber(const std::string &raw) {
  int countDot = 0;
  int countF = 0;
  int countSign = 0;
  size_t posDot = raw.find('.');

  for (size_t i = 0; i < raw.length(); i++) {
    if (raw.at(i) == '.')
      countDot++;
    else if (raw.at(i) == 'f')
      countF++;
    else if (raw.at(i) == '+' || raw.at(i) == '-')
      countSign++;
  }
  if (countDot > 1 || countF > 1 || countSign > 1 ||
      (countSign && !(raw.at(0) == '+' || raw.at(0) == '-')) ||
      (countF && raw.at(raw.length() - 1) != 'f') || (countF && !countDot) ||
      (posDot != std::string::npos &&
       (posDot == raw.length() - 1 || raw.find('f') == posDot + 1)))
    return (ERROR);
  if (countDot && !countF)
    return (DOUBLE);
  else if (countDot && countF)
    return (FLOAT);
  return (INT);
}

e_type getType(const std::string &raw) {
  std::string temp;
  if (raw.length() > 1 && (raw.at(0) == '-' || raw.at(0) == '+') &&
      temp.find_first_of("123567890") != std::string::npos)
    temp = &raw.at(1);
  else
    temp = raw;
  if (temp == "nan" || temp == "nanf" || temp == "+inf" || temp == "-inf" ||
      temp == "+inff" || temp == "-inff")
    return (SPECIAL);
  if (temp.find_last_not_of("+-1234567890.f") == std::string::npos &&
      temp.find_first_of("1234567890") != std::string::npos)
    return (checkNumber(temp));
  if ((temp.length() >= 1 &&
       temp.find_first_not_of("1234567890") != std::string::npos) ||
      temp.find_first_of("123456789.") == std::string::npos) {
    if (checkChar(temp))
      return (CHAR);
    return (ERROR);
  }
  return (INT);
}

//-------------------------------------------------------------------------
//                             Display Type                              //
//-------------------------------------------------------------------------

void displayChar(const std::string &raw) {
  char c = raw[0];

  std::cout << "Char: " << static_cast<char>(c) << std::endl;
  std::cout << "Int: " << static_cast<int>(c) << std::endl;
  std::cout << "Float: " << static_cast<float>(c) << ".0f" << std::endl;
  std::cout << "Double: " << static_cast<double>(c) << ".0" << std::endl;
}

void displayInt(const std::string &raw) {
  int num;
  std::stringstream ss(raw);

  ss >> num;
  if (isascii(num)) {
    if (isprint(num))
      std::cout << "Char: " << static_cast<char>(num) << std::endl;
    else
      std::cout << "Char: not displayable" << std::endl;
  } else
    std::cout << "Char: imposible" << std::endl;
  std::cout << "Int: " << num << std::endl;
  std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
  std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

void displayFloatAndDouble(const std::string &raw) {
  double d;
  std::stringstream ss(raw);

  ss >> d;
  if (isascii(d)) {
    if (isprint(d))
      std::cout << "Char: " << static_cast<char>(d) << std::endl;
    else
      std::cout << "Char: not displayable" << std::endl;
  } else
    std::cout << "Char: imposible" << std::endl;
  std::cout << "Int: " << static_cast<int>(d) << std::endl;
  std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(round(d * 10) / 10) << "f" << std::endl;
  std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<double>(round(d * 10) / 10) << std::endl;
}

//-------------------------------------------------------------------------
//                             main function                             //
//-------------------------------------------------------------------------

void ScalarConverter::convert(const std::string &raw) {
  e_type type;
  type = getType(raw);
  if (type == CHAR)
    displayChar(raw);
  else if (type == INT)
    displayInt(raw);
  else if (type == DOUBLE || type == FLOAT)
    displayFloatAndDouble(raw);
  else
	std::cout << "Input Error" << std::endl;
}
