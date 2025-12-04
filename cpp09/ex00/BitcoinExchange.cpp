#include "BitcoinExchange.hpp"
#include "Date.hpp"

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
			// Convert input date to time_t 
			// std::time_t input_time = Date::to_time_t(it->first);

			// Find the closest date in the database that is <= input date
			std::map<time_t, float>::iterator db_it = m_data_map.upper_bound(Date::to_time_t(it->first));
			
			// upper_bound returns iterator to first element < key
			// So we need to go back one to get the closest lower or equal date
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

