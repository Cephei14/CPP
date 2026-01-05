#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
private:
	std::map<std::string, float> _CoinsData;
public:
	BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

	void LoadData(const std::string& filename);
	void Calculate(const std::string& filename);
	bool isValidDate(const std::string& date);
	bool isValidValue(const std::string& Value);
};

#endif