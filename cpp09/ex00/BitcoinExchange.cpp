#include "BitcoinExchange.hpp"

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



BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
	: m_data(other.m_data), m_input(other.m_input)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		*this = other;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

int BitcoinExchange::readData(const std::string &path)
{
	std::ifstream file(path.c_str());
	std::stringstream buffer;

	buffer << file.rdbuf();

	if (buffer.str().empty())
		return (EXIT_FAILURE);
	this->m_data = buffer.str();
	// logDebug("read data");
	return (EXIT_SUCCESS);
}

int BitcoinExchange::readInput(const std::string &path)
{
	std::ifstream file(path.c_str());
	std::stringstream buffer;

	buffer << file.rdbuf();

	if (buffer.str().empty())
		return (EXIT_FAILURE);
	this->m_input = buffer.str();
	// logDebug("read input");
	m_inputFile = path;
	return (EXIT_SUCCESS);
}

int BitcoinExchange::logError(const std::string &what) const
{
	std::cerr << "ERROR: " << what << std::endl;
	return EXIT_FAILURE;
}

int BitcoinExchange::logDebug(const std::string &what) const
{
	std::cerr << "DEBUG: " << what << std::endl;
	return EXIT_SUCCESS;
}


std::string BitcoinExchange::trim(const std::string &str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, last - first + 1);
}

int BitcoinExchange::parseInput()
{
	std::istringstream ss(m_input);
	std::string line;
	bool first_line = true;
	int i = 0;

	while (std::getline(ss, line))
	{
		++i;
		std::stringstream lineNum;
		lineNum << i;
		// lineNum.str()
		if (line.empty())
			continue;
		if (first_line)
		{
			first_line = false;
			continue;
		}
		size_t pipe_pos = line.find('|');
		if (pipe_pos == std::string::npos)
		{
			// logError("bad input => " + line);
			m_input_map.insert(std::make_pair(m_inputFile + ":" + lineNum.str() +" bad input => " + line, BAD));
			continue;
		}

		std::string date_str = trim(line.substr(0, pipe_pos));
		std::string value_str = trim(line.substr(pipe_pos + 1));

		if (Date::to_time_t(date_str) == -1)
		{
			// logError("invalid date => " + date_str);
			m_input_map.insert(std::make_pair(m_inputFile + ":" + lineNum.str() +" invalid date => " + date_str, BAD));
			continue;
		}

		char *endptr;
		float value = std::strtof(value_str.c_str(), &endptr);

		if (*endptr != '\0' && *endptr != '\n')
		{
			// logError("invalid value => " + value_str);
			m_input_map.insert(std::make_pair(m_inputFile + ":" + lineNum.str() +" invalid value => " + value_str, BAD));
			continue;
		}

		if (value < 0)
		{
			// logError("not a positive number.");
			m_input_map.insert(std::make_pair(m_inputFile + ":" + lineNum.str() +" not a positeve number => " + line, BAD));
			continue;
		}

		if (value > 1000)
		{
			// logError("too large a number.");
			m_input_map.insert(std::make_pair(m_inputFile + ":" + lineNum.str() +" too large number => " + line, BAD));
			continue;
		}

		// Add to map
		m_input_map.insert(std::make_pair(date_str, value));
		// logDebug("Parsed: " + date_str + " | " + value_str);
	}

	return EXIT_SUCCESS;
}

int BitcoinExchange::parseData()
{
	std::istringstream ss(m_data);
	std::string line;
	bool first_line = true;

	while (std::getline(ss, line))
	{
		if (first_line)
		{
			first_line = false;
			continue;
		}
		size_t pipe_pos = line.find(',');
		if (pipe_pos == std::string::npos)
		{
			logError("bad input => " + line);
			continue;
		}

		std::string date_str = trim(line.substr(0, pipe_pos));
		std::string value_str = trim(line.substr(pipe_pos + 1));

		if (Date::to_time_t(date_str) == -1)
		{
			logError("invalid date => " + date_str);
			continue;
		}

		char *endptr;
		float value = std::strtof(value_str.c_str(), &endptr);

		if (*endptr != '\0' && *endptr != '\n')
		{
			logError("invalid value => " + value_str);
			continue;
		}

		if (value < 0)
		{
			logError("not a positive number.");
			continue;
		}

		if (value > 471150.93)
		{
			logError("too large a number.");
			continue;
		}

		// Add to map
		m_data_map[Date::to_time_t(date_str)] = value;
		// logDebug("Parsed: " + date_str + " | " + value_str);
	}

	return EXIT_SUCCESS;
}

int BitcoinExchange::calculate()
{
	for (std::multimap<std::string, float>::iterator it = m_input_map.begin(); it != m_input_map.end(); ++it)
	{
		if(it->second != BAD)
		{

			// Find the closest date in the database that is <= input date
			std::map<time_t, float>::iterator db_it = m_data_map.upper_bound(Date::to_time_t(it->first));
			
			if (db_it == m_data_map.begin())
			{
				logError("no data available for date => " + it->first);
				continue;
			}
			
			--db_it; // Move to the closest lower or equal date
			
			std::cout << it->first << " => " << it->second 
					  << " = " << (db_it->second * it->second) << std::endl;
		}
		else
			logError(it->first);
	}
	return 0;
}

