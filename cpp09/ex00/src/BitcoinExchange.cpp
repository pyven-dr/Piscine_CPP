#include <cstdlib>
#include <fstream>
#include <iostream>
#include "BitcoinExchange.hpp"

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
		date = line.substr(0, 10);
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

void BitcoinExchange::ConvertValue(const std::string &date_str, double value)
{
	std::map<int, double>::iterator it;
	int date = DateToInt(date_str);

	it = this->map.lower_bound(date);
	if (it->first != date && it != this->map.begin())
		--it;
	if (it == this->map.end())
		std::cout << "Can't find any date" << std::endl;
	else
		std::cout << date_str << " => " << value << " = "
			<< value * it->second << std::endl;
}

void BitcoinExchange::ConvertData(const std::string &inputPath)
{
	std::ifstream inputFile(inputPath.c_str());
	std::string line;

	if (inputFile.is_open() == 0)
		throw std::invalid_argument("Can't open input file");
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		try
		{
			CheckInput(line);
			this->ConvertValue(line.substr(0, 10),
						   	std::strtod(line.substr(13).c_str(), NULL));
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	inputFile.close();
}
