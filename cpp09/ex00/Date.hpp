#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <cstdio>


class Date
{
private:
	bool static isLeapYear(int year);
	int static daysInMonth(int year, int month);

public:
	Date() {};
	~Date() {};

	std::time_t static to_time_t(const std::string &date_str);
	std::string static to_string(const std::time_t &date_t);
};
