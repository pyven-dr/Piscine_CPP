#include <cstdlib>
#include <string>
#include <iostream>

int	checkNumber(const std::string &strNumber)
{
	__int64_t number;

	for (std::string::const_iterator it = strNumber.begin();
		it != strNumber.end(); ++it)
	{
		if (std::isdigit(*it) == 0)
		{
			std::cerr << "Invalid Number : " << strNumber << std::endl;
			return (-1);
		}
	}
	number = std::strtol(strNumber.c_str(), NULL, 10);
	if (number >= 10)
	{
		std::cerr << "Number too big : " << strNumber << std::endl;
		return (-1);
	}
	return (static_cast<int>(number));
}

int checkOperator(const std::string &Operator)
{
	std::string operList = "+-/*";
	if (Operator.size() != 1)
		return (-1);
	for (int i = 0; i < 4; ++i)
	{
		if (Operator[0] == operList[i])
			return (0);
	}
	return (-1);
}
