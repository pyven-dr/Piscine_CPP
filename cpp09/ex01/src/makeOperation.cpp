#include <cstdlib>
#include <iostream>

__int64_t makeOperation(char Operator, __int64_t firstNum, __int64_t secNum)
{
	switch (Operator)
	{
		case '+':
			return (secNum + firstNum);

		case '-':
			return (secNum - firstNum);

		case '*':
			return (secNum * firstNum);

		case '/':
			if (firstNum == 0)
			{
				std::cerr << "Can't divide by zero" << std::endl;
				return (-1);
			}
			return (secNum / firstNum);

		default:
			return (-1);
	}
}
