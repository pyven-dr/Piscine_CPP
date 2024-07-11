#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a(1.5f);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a = " << a << std::endl;
	std::cout << "++a = "<< ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "--a = "<< --a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << std::endl;

	std::cout << "b = " << b << std::endl;

	std::cout << "a < b = " << (a < b) << std::endl;
	std::cout << "a <= b = " << (a <= b) << std::endl;
	std::cout << "a > b = " << (a > b) << std::endl;
	std::cout << "a >= b = " << (a >= b) << std::endl;
	std::cout << "a == b = " << (a == b) << std::endl;
	std::cout << "a != b = " << (a != b) << std::endl;
	std::cout << std::endl;

	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl;
	std::cout << std::endl;

	std::cout << "max(a , b) = " << Fixed::max( a, b ) << std::endl;
	std::cout << "min(a , b) = " << Fixed::min( a, b ) << std::endl;
	return 0;
}