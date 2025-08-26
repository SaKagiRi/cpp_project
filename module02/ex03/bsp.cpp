#include "Point.hpp"
#include "Fixed.hpp"

float	calculate_area(const Point a, const Point b, const Point c)
{
	int	res = ((b.getX() - a.getX()) * (c.getY() - a.getY())) \
		- ((b.getY() - a.getY()) * (c.getX() - a.getX()));
	return (res);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	int	area = calculate_area(a, b, c);
	int	ab = calculate_area(a, b, point);
	int	ac = calculate_area(a, point, c);
	int	bc = calculate_area(point, b, c);

	if (ab == 0 || ac == 0 || bc == 0)
		return (false);
	if ((ab < 0 && ac < 0 && bc < 0 && ab + ac + bc == area) \
		||(ab > 0 && ac > 0 && bc > 0 && ab + ac + bc == area) )
		return (true);
	return (false);
}
