#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <cstdio>

// need to make funct to parse date into time(int) and back(str)

std::time_t parse_date_to_time_t(const std::string &date_str)
{
	int year = 0, month = 0, day = 0;
	if (std::sscanf(date_str.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
		return (std::time_t)-1;

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return (std::time_t)-1;

	std::tm tm = {};
	tm.tm_year = year - 1900; // years since 1900
	tm.tm_mon = month - 1;    // months since January [0,11]
	tm.tm_mday = day;
	tm.tm_hour = 0;
	tm.tm_min = 0;
	tm.tm_sec = 0;

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

std::string time_t_to_string(std::time_t t)
{
	if (t == (std::time_t)-1)
		return std::string("Bad timestamp");

	std::tm tm = *std::localtime(&t); // or std::gmtime(&t) if you prefer UTC
	char buf[16];
	if (std::strftime(buf, sizeof(buf), "%Y-%m-%d", &tm) == 0)
		return std::string("Bad timestamp");
	return std::string(buf);
}

int main()
{

	// Demonstration: valid and invalid inputs
	const char *tests[] = {"2011-01-03", "2011-45-56", "2014-10-26", "2000-02-29", NULL};
	for (const char **p = tests; *p; ++p)
	{
		std::time_t t = parse_date_to_time_t(*p);
		std::cout << *p << " -> " << time_t_to_string(t) << '\n';
	}
	return 0;
}
