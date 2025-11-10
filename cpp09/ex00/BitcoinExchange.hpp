#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
private:
	std::string m_data;
	std::string m_input;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	int readData(const std::string &path);
	int readInput(const std::string &path);

	int printError(const std::string &what) const;
};

