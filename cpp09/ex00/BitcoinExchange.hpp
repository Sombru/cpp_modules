#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <map>
#include <ctime>

class BitcoinExchange
{
private:
	std::string m_data;
	std::string m_input;

	std::map<std::string, float> m_input_map; 
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	int readData(const std::string &path);
	int readInput(const std::string &path);

	int logError(const std::string &what) const;
	int logDebug(const std::string &what) const;

	bool isValidDate(const std::string &date_str);
	int parseInput();
};

