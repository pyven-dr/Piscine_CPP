#include "Point.hpp"
#include <iostream>

int main(void)
{
	Point a(1.85, 5.46);
	Point b(1.4, 3.4);
	Point c(7.65, 8.64);

	Point p1(2.59737, 4.90614);
	Point p2(5.7307, 3.21579);
	Point p3(1.85, 4.46);

	if (bsp(a, b, c, p3) == true)
		std::cout << "point in the triangle" << std::endl;
	else
		std::cout << "point outside of the triangle" << std::endl;
	return 0;
}