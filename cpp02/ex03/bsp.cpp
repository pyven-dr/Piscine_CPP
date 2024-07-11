#include "Point.hpp"

Fixed	find_abs(const Fixed& number)
{
	if (number < Fixed(0))
		return (number * -1);
	return (number);
}

Fixed	find_area(const Point& a, const Point& b, const Point& c)
{
	Fixed n1(a.getX() * (b.getY() - c.getY()));
	Fixed n2(b.getX() * (c.getY() - a.getY()));
	Fixed n3(c.getX() * (a.getY() - b.getY()));

	return (Fixed(0.5f) * find_abs((n1 + n2 + n3)));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed T_area = find_area(a, b, c);
	Fixed area1 = find_area(a, b, point);
	Fixed area2 = find_area(a, c, point);
	Fixed area3 = find_area(b ,c, point);

	if ((area1 + area2 + area3) == T_area)
		return (true);
	return (false);
}