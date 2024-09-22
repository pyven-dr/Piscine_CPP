#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>

#define CSV_PATH "./data.csv"

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange(void);

		void ConvertData(const std::string &inputPath);
		void ConvertValue(const std::string &date_str, double value);

	private:
		std::map<int, double> map;
};

void CheckInput(const std::string &line);
int DateToInt(const std::string &date);

#endif
