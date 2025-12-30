#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <map>
#include <ctime>

#define BAD -69.1f

class BitcoinExchange
{
private:
	std::string m_data;
	std::string m_input;
	std::string m_inputFile;

	std::multimap<std::string, float> m_input_map; 
	std::map<time_t, float> m_data_map; 
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




class Date
{
private:
	bool static isLeapYear(int year);
	int static daysInMonth(int year, int month);

public:
	// Date() {};
	// ~Date() {};

	std::time_t static to_time_t(const std::string &date_str);
	std::string static to_string(const std::time_t &date_t);
};
