#pragma once

#include <exception>
#include <iostream>
#include <list>

class Span {
private:
	unsigned int _maximumNumber;
	std::list<int> _list;
public:
	Span(void);
	Span(unsigned int N);
	~Span(void);
	Span(const Span& source);
	Span& operator=(const Span& source);

	void addNumber(int n);
	void addMultipleNumber(int start, int stop);
	int shortestSpan(void);
	int longestSpan(void);

	class listIsFull: public std::exception {
		public:
			virtual const char *what() const throw();
	};

	class canNotSpan: public std::exception {
		public:
			virtual const char *what() const throw();
	};
};
