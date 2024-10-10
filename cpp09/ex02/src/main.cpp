#include <iostream>
#include <ctime>
#include <iomanip>
#include <exception>
#include "PmergeMe.hpp"


int main(int argc, char** argv)
{
	PmergeMe sort;
	std::clock_t time;

	if (argc == 1)
	{
		std::cout << "Not enough arguments" << std::endl;
		return (1);
	}
	try
	{
		sort.FillClass(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}

	std::cout << "Before: " << sort;
	time = std::clock();
	sort.SortVector();
	time = std::clock() - time;
	std::cout << "After: " << sort;
	std::cout << "Time to process a range of " << argc - 1 <<
		" elements with std::vector : ";
	std::cout << std::setprecision(6) << std::fixed;
	std::cout << static_cast<double>(time) / CLOCKS_PER_SEC << "s" << std::endl;

	time = std::clock();
	sort.SortDeque();
	time = std::clock() - time;
	std::cout << "Time to process a range of " << argc - 1 <<
		" elements with std::deque : ";
	std::cout << std::setprecision(6) << std::fixed;
	std::cout << static_cast<double>(time) / CLOCKS_PER_SEC << "s" << std::endl;

	return (0);
}
