#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include "BitcoinExchange.hpp"

int DateToInt(std::string date)
{
	int dateInt;

	dateInt = std::atoi(date.substr(0,4).c_str()) * 10000;
	dateInt += std::atoi(date.substr(5,2).c_str()) * 100;
	dateInt += std::atoi(date.substr(8,2).c_str());
	return (dateInt);
}

BitcoinExchange::BitcoinExchange(void)
{
	std::ifstream file_csv(CSV_PATH);
	std::string line;
	std::string date;
	std::string exchange_rate;

	if (file_csv.is_open() == 0)
		throw std::invalid_argument("Can't open csv file");
	std::getline(file_csv, line);
	while (std::getline(file_csv, line))
	{
		date = line.substr(0,10);
		exchange_rate = line.substr(11);
		this->map[DateToInt(date)] = std::strtod(exchange_rate.c_str(), NULL);
	}
	file_csv.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : map(copy.map) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->map = other.map;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {}

void BitcoinExchange::displayMap()
{
	for (std::map<int, double>::const_iterator it = this->map.begin(); it != this->map.end(); ++it) {
		std::cout << std::setprecision(10) << "Date: " << it->first << ", Value: " << it->second << std::endl;
	}
}

void check_date(const std::string &date)
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

void check_value(const std::string &value)
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

void check_input(const std::string &line)
{
	if (line.length() < 14)
		throw std::invalid_argument("Bad input => " + line);
	check_date(line.substr(0, 10));
	if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		throw std::invalid_argument("Bad input => " + line);
	check_value(line.substr(13));
}

void BitcoinExchange::ConvertValue(const std::string &date_str, const double value)
{
	std::map<int, double>::iterator it;
	int date = DateToInt(date_str);

	it = this->map.lower_bound(date);
	if (it->first != date && it != this->map.begin())
		--it;
	if (it == this->map.end())
		std::cout << "Can't find any date" << std::endl;
	else
		std::cout << date_str << " => " << value << " = " << value * it->second << std::endl;
}

void BitcoinExchange::ConvertData(const std::string &inputPath)
{
	std::ifstream inputFile(inputPath.c_str());
	std::string line;
	bool exception = true;

	if (inputFile.is_open() == 0)
		throw std::invalid_argument("Can't open input file");
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		try
		{
			check_input(line);
			exception = false;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		if (exception == false)
			this->ConvertValue(line.substr(0,10),
						   	std::strtod(line.substr(13).c_str(), NULL));
		exception = true;
	}
	inputFile.close();
}