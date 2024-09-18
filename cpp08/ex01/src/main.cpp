#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main(void)
{
	Span span(5);

	try
	{
		std::cout << span.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << span.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	span.addNumber(6);
	span.addNumber(3);
	span.addNumber(17);
	span.addNumber(9);
	span.addNumber(11);

	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << "\n" << std::endl;


	std::srand(static_cast<unsigned int>(std::time(0)));
	std::vector<int> vector;
	for (int i = 0; i < 10000; i++)
		vector.push_back(std::rand());

	Span span2(10000);

	span2.addNumbers(vector.begin(), vector.end());
	std::cout << span2.shortestSpan() << std::endl;
	std::cout << span2.longestSpan() << std::endl;
	return (0);
}
