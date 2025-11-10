#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) 
	: m_data(other.m_data), m_input(other.m_input)
{}

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
	return (EXIT_SUCCESS);
}

int BitcoinExchange::printError(const std::string &what) const
{
	std::cerr << "Error: " << what << std::endl;
	return EXIT_FAILURE;
}