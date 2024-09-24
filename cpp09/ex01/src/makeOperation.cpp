#include <cstdlib>

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
			return (secNum / firstNum);

		default:
			return (-1);
	}
}
