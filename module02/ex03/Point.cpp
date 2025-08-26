#include "Point.hpp"

Point&	Point::operator=(const Point& source)
{
	(void)source;
	return (*this);
}

Point::~Point(void)
{
}

int	Point::getX(void) const{
	return (_a.getRawBits());
}

int	Point::getY(void) const{
	return (_b.getRawBits());
}
