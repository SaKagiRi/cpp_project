#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void): _rawBits(0) {}
Fixed::Fixed(const Fixed& other)
{
	*this = other;
}
Fixed::Fixed(const int raw): _rawBits(raw * (1 << _fBit)) {}
Fixed::Fixed(const float raw): _rawBits(roundf(raw * (1 << _fBit))) {}
Fixed::~Fixed(void) {}

Fixed&		Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		_rawBits = other._rawBits;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (_rawBits);
}

void	Fixed::setRawBits(const int raw)
{
	_rawBits = raw;
}

int	Fixed::toInt(void) const
{
	return (_rawBits >> _fBit);
}

float	Fixed::toFloat(void) const
{
	return ((float)_rawBits / (1 << _fBit));
}

bool	Fixed::operator<(const Fixed& source)const
{
	if (getRawBits() < source.getRawBits())
		return (true);
	return (false);
}
bool	Fixed::operator<=(const Fixed& source)const
{
	if (getRawBits() <= source.getRawBits())
		return (true);
	return (false);
}
bool	Fixed::operator>(const Fixed& source)const
{
	if (getRawBits() > source.getRawBits())
		return (true);
	return (false);
}
bool	Fixed::operator>=(const Fixed& source)const
{
	if (getRawBits() >= source.getRawBits())
		return (true);
	return (false);
}
bool	Fixed::operator==(const Fixed& source)const
{
	if (getRawBits() == source.getRawBits())
		return (true);
	return (false);
}
bool	Fixed::operator!=(const Fixed& source)const
{
	if (getRawBits() != source.getRawBits())
		return (true);
	return (false);
}

float	Fixed::operator+(const Fixed& source)const
{
	Fixed	res(toFloat() + source.toFloat());

	return (res.toFloat());
}
float	Fixed::operator-(const Fixed& source)const
{
	Fixed	res(toFloat() - source.toFloat());

	return (res.toFloat());
}
float	Fixed::operator*(const Fixed& source)const
{
	Fixed	res(toFloat() * source.toFloat());

	return (res.toFloat());
}
float	Fixed::operator/(const Fixed& source)const
{
	if (source.toFloat() == 0 || toFloat() == 0)
		return (0);
	Fixed	res(toFloat() / source.toFloat());

	return (res.toFloat());
}

Fixed	Fixed::operator--(void)
{
	setRawBits(getRawBits() - 1);
	return (*this);
}
Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	setRawBits(getRawBits() - 1);
	return (temp);
}
Fixed	Fixed::operator++(void)
{
	setRawBits(getRawBits() + 1);
	return (*this);
}
Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	setRawBits(getRawBits() + 1);
	return (temp);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}
Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fix)
{
	os<< fix.toFloat();
	return (os);
}
