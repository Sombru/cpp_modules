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

	std::multimap<std::string, float> m_input_map; 
	std::map<std::string, float> m_data_map; 
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	int readData(const std::string &path);
	int readInput(const std::string &path);

	int logError(const std::string &what) const;
	int logDebug(const std::string &what) const;

	std::string trim(const std::string &str);
	bool isValidDate(const std::string &date_str);
	int parseInput();
	int parseData();
	int calculate();
};

