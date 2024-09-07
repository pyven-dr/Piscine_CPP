#include <iostream>
#include "iter.hpp"

template<typename Array>
void print_char(Array& n)
{
	std::cout << n << std::endl;
}

template<typename Array>
void toUpper(Array &c)
{
	c = std::toupper(c);
}

int main(void)
{
	char *array = new char[10];
	const char const_array[] = "abcdefghij";
	for (int i = 0; i < 10; i++)
	{
		array[i] = static_cast<char>(i + 97);
		std::cout << "array : " << array[i] << std::endl;
		std::cout << "const_array : " << const_array[i] << std::endl;
	}
	std::cout  << std::endl;

	::iter(const_array, 10, print_char);
	std::cout << std::endl;
	::iter(array, 10, toUpper);

	for (int i = 0; i < 10; i++)
		std::cout << array[i] << std::endl;

	delete[] array;
	return (0);
}
