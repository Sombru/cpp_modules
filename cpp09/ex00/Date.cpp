#include "Date.hpp"

// need to make funct to parse date into time(int) and back(str)

// helper: leap year and days-in-month
bool Date::isLeapYear(int year)
{
	return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

int Date::daysInMonth(int year, int month)
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		return isLeapYear(year) ? 29 : 28;
	default:
		return 0;
	}
}

std::time_t Date::to_time_t(const std::string &date_str)
{
	int year = 0, month = 0, day = 0;
	if (std::sscanf(date_str.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
		return (std::time_t)-1;

	// basic month/day bounds
	if (month < 1 || month > 12 || day < 1)
		return (std::time_t)-1;

	if (day > daysInMonth(year, month))
		return (std::time_t)-1;

	std::tm tm = {};
	tm.tm_year = year - 1900; // years since 1900
	tm.tm_mon = month - 1;	  // months since January [0,11]
	tm.tm_mday = day;

	// mktime interprets tm as local time
	std::time_t t = std::mktime(&tm);
	if (t == (std::time_t)-1)
		return (std::time_t)-1;

	// Now recheck to ensure mktime didn't normalize the date (like Feb 30 -> Mar 2)
	std::tm tm_check = *std::localtime(&t);
	if (tm_check.tm_year != tm.tm_year ||
		tm_check.tm_mon != tm.tm_mon ||
		tm_check.tm_mday != tm.tm_mday)
		return (std::time_t)-1;

	return t;
}

std::string Date::to_string(const	 std::time_t &t)
{
	if (t == (std::time_t)-1)
		return std::string("Bad date");

	std::tm tm = *std::localtime(&t); 
	char buf[16];
	if (std::strftime(buf, sizeof(buf), "%Y-%m-%d", &tm) == 0)
		return std::string("Bad date");
	return std::string(buf);
}
