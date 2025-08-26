#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:
		const	Fixed	_a;
		const	Fixed	_b;
	public:
		Point(void): _a(Fixed(0)), _b(Fixed(0)) {}
		Point(const Fixed a, const Fixed b): _a(a), _b(b) {}
		Point(const Point& source): _a(source._a), _b(source._b) {}
		Point&	operator=(const Point& source);
		~Point(void);

		int	getX(void) const;
		int	getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
