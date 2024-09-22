#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange Exchange;
		Exchange.ConvertData(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}