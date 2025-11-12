#pragma once

#include <exception>
#include <iostream>

class notOccurrence : public std::exception {
  virtual const char *what() const throw() { return ("not occurrecne"); }
};

template <typename T> typename T::iterator easyfind(T a, int b) {
  for (typename T::iterator it = a.begin(); it != a.end(); it++) {
    if (*it == b)
      return (it);
  }
  throw(notOccurrence());
}
