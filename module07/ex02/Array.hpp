#pragma once

#include <exception>
#include <iostream>

template <typename T> class Array {
private:
  T *arr;
  size_t _size;

public:
	class out_of_bound: public std::exception {
		public:
		virtual const char *what(void) const throw(){
			return "index out of bound";
		}
	};
  Array(void) {
    arr = NULL;
    _size = 0;
  }
  Array(unsigned int n) {
    arr = new T[n];
    _size = n;
	for (size_t i = 0; i < _size; i++)
			arr[i] = 0;
  }
  Array(const Array &source) {
    if (this != &source) {
      _size = source._size;
      arr = new T[source._size];
      for (size_t i = 0; i < _size; i++)
        arr[i] = source.arr[i];
    }
  }
  ~Array(void) {
    if (_size > 0)
      delete[] arr;
  }
  Array &operator=(const Array &source) {
    if (this != &source) {
      if (_size > 0)
        delete[] arr;
      _size = source._size;
      arr = new T[source._size];
      for (size_t i = 0; i < _size; i++)
        arr[i] = source.arr[i];
    }
		(void)source;
    return (*this);
  }
  T &operator[](int n) const {
    if (n < 0 || n >= static_cast<int>(_size)) {
      throw (out_of_bound());
    }
    return (arr[n]);
  }
  size_t size(void) { return (_size); }
};
