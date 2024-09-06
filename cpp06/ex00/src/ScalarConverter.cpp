#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <limits>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	static_cast <void>(copy);
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	static_cast <void>(other);
	return (*this);
}

ScalarConverter::~ScalarConverter(void) {}

void printDouble(const double litteral)
{
	if (std::fabs(litteral - static_cast<int>(litteral)) < 1e-10)
		std::cout << "double: " << std::fixed << std::setprecision(1) \
			<< litteral  << std::endl;
	else
		std::cout << "double: " << std::setprecision(10) \
			<< litteral  << std::endl;
}

void printInt(const double litteral)
{
	if (std::isnan(litteral) || std::isinf(litteral))
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	else if (litteral > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: Error: Overflow" << std::endl;
	else if (litteral < static_cast<double>(std::numeric_limits<int>::min()))
		std::cout << "int: Error: Underflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(litteral) << std::endl;
}

void printFloat(const double litteral)
{
	if (std::isnan(litteral) || std::isinf(litteral))
		std::cout << "float: " << static_cast<float>(litteral) << "f" << std::endl;
	else if (litteral > static_cast<double>(std::numeric_limits<float>::max()))
		std::cout << "float: Error: Overflow" << std::endl;
	else if (litteral < -static_cast<double>(std::numeric_limits<float>::max()))
		std::cout << "float: Error: Underflow" << std::endl;
	else
	{
		if (std::fabs(litteral - static_cast<int>(litteral)) < 1e-10)
			std::cout << "float: " << std::fixed << std::setprecision(1) \
				<< litteral << "f" << std::endl;
		else
			std::cout << "float: " << std::setprecision(6) \
				<< litteral << "f" << std::endl;
	}
}

void printChar(const double litteral)
{
	if (std::isnan(litteral) || std::isinf(litteral))
		std::cout << "char: impossible" << std::endl;
	else if (litteral > static_cast<double>(std::numeric_limits<char>::max()))
		std::cout << "char: Error: Overflow" << std::endl;
	else if (litteral < static_cast<double>(std::numeric_limits<char>::min()))
		std::cout << "char: Error: Underflow" << std::endl;
	else if (std::isprint(static_cast<char>(litteral)) == 0)
		std::cout << "char: Error: Non printable" << std::endl;
	else
		std::cout << "float: " << static_cast<char>(litteral) << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
	double double_litteral;

	if (literal.length() == 1 && std::isdigit(literal[0]) == 0)
		double_litteral = static_cast<char>(literal[0]);
	else
		double_litteral = std::strtod(literal.c_str(), NULL);

	printChar(double_litteral);
	printInt(double_litteral);
	printFloat(double_litteral);
	printDouble(double_litteral);
}
