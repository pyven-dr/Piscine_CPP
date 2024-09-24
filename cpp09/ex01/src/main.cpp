#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (1);
	}
	RPN rpnClass;

	rpnClass.resolve(argv[1]);
	return (0);
}
