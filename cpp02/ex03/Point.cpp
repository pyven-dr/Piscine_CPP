#include "Point.hpp"
#include <iostream>

Point::Point() : x(0), y(0)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::Point(const Point &copy) : x(copy.getX()), y(copy.getY())
{
}

Point& Point::operator=(const Point &other)
{
	(void)other;
	std::cout << "Can't modify const variables" << std::endl;
	return (*this);
}

Point::~Point()
{
}

const Fixed& Point::getX() const
{
	return (this->x);
}

const Fixed& Point::getY() const
{
	return (this->y);
}