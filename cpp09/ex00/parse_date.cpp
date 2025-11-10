#include <iostream>
#include <sstream>
#include <ctime>

std::time_t parse_date_to_time_t(const std::string &date_str)
{
	std::tm tm = {};
	std::istringstream ss(date_str);
	char sep1, sep2;

`	if (!(ss >> tm.tm_year >> sep1 >> tm.tm_mon >> sep2 >> tm.tm_mday))
		return -1;
	if (sep1 != '-' || sep2 != '-')
		return -1;

	tm.tm_year -= 1900; // struct tm counts years since 1900
	tm.tm_mon -= 1;		// struct tm months are 0-based

	std::time_t t = std::mktime(&tm);

	// mktime normalizes invalid dates (e.g. Feb 30 → Mar 2)
	std::tm *check = std::gmtime(&t);
	if (check->tm_year != tm.tm_year ||
		check->tm_mon != tm.tm_mon ||
		check->tm_mday != tm.tm_mday)
		return -1;

	return t;
}

int main()
{
	std::time_t t = parse_date_to_time_t("2011-01-03");
	if (t != -1)
		std::cout << "Unix time: " << t << '\n';
	else
		std::cout << "Invalid date\n";
}
