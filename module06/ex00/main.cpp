#include "ScalarConverter.hpp"

int main(int c, char **v) {
  std::string str;
  if (c != 2)
    return (1);
  str = v[1];
  ScalarConverter::convert(str);
}
