#include <cstdlib>
#include <string>

int DateToInt(const std::string &date)
{
	int dateInt;

	dateInt = std::atoi(date.substr(0, 4).c_str()) * 10000;
	dateInt += std::atoi(date.substr(5, 2).c_str()) * 100;
	dateInt += std::atoi(date.substr(8, 2).c_str());
	return (dateInt);
}
