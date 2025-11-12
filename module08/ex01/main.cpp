#include "Span.hpp"

int main(void) {
  try {
    Span s(10);

    s.addNumber(10);
    s.addNumber(1);
    s.addNumber(5);
    s.addNumber(14);
    s.addNumber(-1);
    s.addNumber(11);
    s.addNumber(11);
    std::cout << s.shortestSpan() << std::endl;
    std::cout << s.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Span s; // size == 2

    s.addNumber(10);
    s.addNumber(1);
    s.addNumber(5);
    s.addNumber(14);
    s.addNumber(-1);
    s.addNumber(11);
    s.addNumber(11);
    std::cout << s.shortestSpan() << std::endl;
    std::cout << s.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Span s; // size == 2

    s.addNumber(10);
    std::cout << s.shortestSpan() << std::endl;
    std::cout << s.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Span s(100000);

    s.addMultipleNumber(0, 100000);
    std::cout << s.shortestSpan() << std::endl;
    std::cout << s.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
