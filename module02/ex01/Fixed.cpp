#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_rawBits = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int raw)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = raw * (1 << _fBit);
}

Fixed::Fixed(const float raw)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(raw * (1 << _fBit));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&		Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_rawBits = other._rawBits;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits(const int raw)
{
	this->_rawBits = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

int	Fixed::toInt(void) const
{
	return (_rawBits >> _fBit);
}

float	Fixed::toFloat(void) const
{
	return ((float)_rawBits / (1 << _fBit));
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fix)
{
	os << fix.toFloat();
	return (os);
}
