#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

// neet to make funct to parse date into time(int) and back(str)

std::time_t parse_date_to_time_t(const std::string &date_str)
{
	std::tm tm = {};
	std::stringstream ss(date_str);

	ss >> tm.tm_year; // year ("2003")
	ss >> tm.tm_mon; // month ("-01")
	ss >> tm.tm_mday; // dat ("-09")

	if (!ss)
		return -1;
	tm.tm_mon *= -1;
	tm.tm_mday *= -1;

	tm.tm_year -= 1900; // years since 1900
	tm.tm_mon -= 1;		// months since January [0,11]
	// std::cout << "year: " << tm.tm_year << '\n';
	// std::cout << "month: " << tm.tm_mon << '\n';
	// std::cout << "day: " << tm.tm_mday << '\n';

	// mktime interprets tm as local time
	std::time_t t = std::mktime(&tm);
	if (t == -1)
		return -1;
	// std::cout << "year: " << tm.tm_year << '\n';
	// std::cout << "month: " << tm.tm_mon << '\n';
	// std::cout << "day: " << tm.tm_mday << '\n';

	// Now recheck to ensure mktime didn't normalize the date (like Feb 30 -> Mar 2)
	std::tm tm_check = *std::localtime(&t);
	if (tm_check.tm_year != tm.tm_year ||
		tm_check.tm_mon != tm.tm_mon ||
		tm_check.tm_mday != tm.tm_mday)
		return -1;

	return t;
}

std::string time_t_to_string(std::time_t t)
{
	std::cout << t << '\n';
	std::tm tm = *std::localtime(&t); // or std::gmtime(&t) if you prefer UTC
	std::ostringstream ss;
	ss << std::put_time(&tm, "%Y-%m-%d");
	return ss.str();
}

int main()
{
	// std::string test = "2011-01-03";
	// std::stringstream ss(test);
	// int token;
	// size_t pos = -1;

	// while (ss >> token)
	// {
	// 	std::cout << std::abs(token) << '\n';
	// }

	std::cout << time_t_to_string(parse_date_to_time_t("2011-45-56"));
}
