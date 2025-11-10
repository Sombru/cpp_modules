#include "BitcoinExchange.hpp"

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
	logDebug("read data");
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
	logDebug("read input");
	return (EXIT_SUCCESS);
}

int BitcoinExchange::logError(const std::string &what) const
{
	std::cerr << "DEBUG: " << what << std::endl;
	return EXIT_FAILURE;
}

int BitcoinExchange::logDebug(const std::string &what) const
{
	std::cerr << "DEBUG: " << what << std::endl;
	return EXIT_SUCCESS;
}

bool BitcoinExchange::isValidDate(const std::string &date_str)
{
	int y, m, d;
	char sep1, sep2;

	std::istringstream ss(date_str);
	if (!(ss >> y >> sep1 >> m >> sep2 >> d))
		return false;
	if (sep1 != '-' || sep2 != '-')
		return false;

	// Basic range checks
	if (m < 1 || m > 12 || d < 1)
		return false;

	// Days per month
	static const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int dim = days_in_month[m - 1];
	// Leap year check
	if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)))
		dim = 29;

	if (d > dim)
		return false;

	return true;
}


int BitcoinExchange::parseInput()
{
	
}