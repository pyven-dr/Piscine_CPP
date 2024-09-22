#include <cstdlib>
#include <stdexcept>
#include <string>

static void CheckDate(const std::string &date)
{
	int month;
	int day;

	for (int i = 0; i < static_cast<int>(date.length()); i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				throw std::invalid_argument("Invalid date => " + date);
		}
		else if (std::isdigit(date[i]) == 0)
			throw std::invalid_argument("Invalid date => " + date);
	}
	month = std::atoi(date.substr(5,2).c_str());
	day = std::atoi(date.substr(8,2).c_str());
	if (month == 0 || month > 12)
		throw std::invalid_argument("Invalid date => " + date);
	if (day == 0 || day > 31)
		throw std::invalid_argument("Invalid date => " + date);
}

static void CheckValue(const std::string &value)
{
	int i = 0;
	double number;

	while (i < static_cast<int>(value.length()) && value[i] != '.')
	{
		if (std::isdigit(value[i]) == 0)
			throw std::invalid_argument("Invalid value => " + value);
		++i;
	}
	++i;
	while (i < static_cast<int>(value.length()))
	{
		if (std::isdigit(value[i]) == 0)
			throw std::invalid_argument("Invalid value => " + value);
		++i;
	}
	number = std::strtod(value.c_str(), NULL);
	if (number > 1000 || number < 0)
		throw std::invalid_argument("Invalid value => " + value);
}

void CheckInput(const std::string &line)
{
	if (line.length() < 14)
		throw std::invalid_argument("Bad input => " + line);
	CheckDate(line.substr(0, 10));
	if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		throw std::invalid_argument("Bad input => " + line);
	CheckValue(line.substr(13));
}