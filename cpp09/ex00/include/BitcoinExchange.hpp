#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <map>

#define CSV_PATH "./data.csv"

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange(void);

		void ConvertData(const std::string &inputPath);
		void ConvertValue(const std::string &date_str, const double value);
		void displayMap(void);

	private:
		std::map<int, double> map;
};

#endif