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
	bool isLeapYear(int year);
	int daysInMonth(int year, int month);

public:
	Date() {};
	~Date() {};

	std::time_t to_time_t(const std::string &date_str);
	std::string to_string(const std::time_t &date_t);
};
