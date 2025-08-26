#include <iostream>
#include "Point.hpp"

int	main(void)
{
	{
		Point	a(Fixed(0), Fixed(0));
		Point	b(Fixed(4), Fixed(0));
		Point	c(Fixed(0), Fixed(3));
		Point	d(Fixed(0.1f), Fixed(2.923f));
		Point	e(Fixed(0), Fixed(2.923f));
		Point	f(Fixed(0.1f), Fixed(3));

		std::cout << "A(" << a.getX() / (1 << 8) << "," << a.getY() / (1 << 8) << ")" << std::endl;
		std::cout << "B(" << b.getX() / (1 << 8) << "," << b.getY() / (1 << 8) << ")" << std::endl;
		std::cout << "C(" << c.getX() / (1 << 8) << "," << c.getY() / (1 << 8) << ")" << std::endl;
		std::cout << "D(" << d.getX() / (1 << 8) << "," << d.getY() / (1 << 8) << ")" << std::endl;
		std::cout << "E(" << e.getX() / (1 << 8) << "," << e.getY() / (1 << 8) << ")" << std::endl;
		std::cout << "F(" << f.getX() / (1 << 8) << "," << f.getY() / (1 << 8) << ")" << std::endl;
		std::cout << "D Point: " << bsp(a, b, c, d) << std::endl;
		std::cout << "E Point: " << bsp(a, b, c, e) << std::endl;
		std::cout << "F Point: " << bsp(a, b, c, f) << std::endl;
	}
}
