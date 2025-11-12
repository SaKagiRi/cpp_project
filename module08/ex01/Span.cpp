#include "Span.hpp"

Span::Span(void) {
	_maximumNumber = 2;
}
Span::Span(unsigned int N) {
	_maximumNumber = N;
}
Span::~Span(void) {}
Span::Span(const Span& source) {
	if (this != &source)
	{
		_maximumNumber = source._maximumNumber;
		_list.assign(source._list.begin(), source._list.end());
	}
}
Span& Span::operator=(const Span& source) {
	if (this != &source)
	{
		_maximumNumber = source._maximumNumber;
		if (_list.size() != 0)
			_list.clear();
		_list.assign(source._list.begin(), source._list.end());
	}
	return (*this);
}

void Span::addNumber(int n){
	if (_list.size() < _maximumNumber)
		_list.push_back(n);
	else
		throw(listIsFull());
}

void Span::addMultipleNumber(int start, int stop)
{
	int sign = 1;

	if (start == stop)
	{
		addNumber(start);
		return ;
	}
	if (start > stop)
		sign = -1;
	for (int i = start; i != stop; i += sign)
		addNumber(i);
}

const char* Span::listIsFull::what() const throw()
{
	return ("This list is already full");
}

const char* Span::canNotSpan::what() const throw()
{
	return ("Item in list is not enough");
}

int Span::shortestSpan(void){
	std::list<int>::iterator after;
	int gap = -1;

	if (_list.size() < 2)
		throw(canNotSpan());
	_list.sort();
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
	{
		after = it;
		after++;
		if (after != _list.end())
		{
			if (gap == -1 || gap > *after - *it)
				gap = *after - *it;
		}
	}
	return (gap);
}
int Span::longestSpan(void){
	if (_list.size() < 2)
		throw(canNotSpan());
	_list.sort();
	return (*--_list.end() - *_list.begin());
}

