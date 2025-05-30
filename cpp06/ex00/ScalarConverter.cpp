#include "ScalarConverter.hpp"
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <climits>

// convert() takes a string as an argumnet and converts it into one of these
// • char
// • int
// • float
// • double
// and prints it to stdout

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)(other); }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

// nan == not a number
// inf == infinity 
static inline bool isPseudoLiteral(const std::string &s)
{
	return (s == "nan" || s == "nanf" ||
			s == "+inf" || s == "+inff" ||
			s == "-inf" || s == "-inff" ||
			s == "inf" || s == "inff");
}

void ScalarConverter::convert(const std::string &param)
{
	double value = 0.0;
	bool isCharLiteral = false;
	bool isImpossible = false;

	if (param.length() == 1 && !std::isdigit(param[0]))
	{
		value = static_cast<double>(param[0]);
		isCharLiteral = true;
	}
	else if (isPseudoLiteral(param)) // handle nan
	{
		if (param.find('f') != std::string::npos)
			value = std::strtof(param.c_str(), NULL);
		else
			value = std::strtod(param.c_str(), NULL);
		isImpossible = true; // char and int impossible for pseudo-literals
	}
	else
	{
		char *endptr = NULL; // to check if it last char is 'f'
		value = std::strtod(param.c_str(), &endptr);
		if (endptr && *endptr && *endptr != 'f')
		{
			isImpossible = true;
		}
	}

	std::cout << "char: "; // CHAR handler
	if (isImpossible || isascii(value) == false)
		std::cout << "impossible\n";
	else if (isprint(value) == false)
		std::cout << "not displayable\n";
	else
	{
		std::cout << static_cast<char>(value) << '\n';
	}

	std::cout << "int: "; // INT handler
	if (isImpossible || std::isnan(value) || value < INT_MIN || value > INT_MAX)
		std::cout << "impossible\n";
	else
	{
		std::cout << static_cast<int>(value) << '\n';
	}

	std::cout << "float: "; //FLOAT handler
	std::cout << std::fixed << std::setprecision(1);
	if (isImpossible || std::isnan(value) || value < INT_MIN || value > INT_MAX)
		std::cout << "impossible\n";
	else if (isPseudoLiteral(param))
	{
		if (param == "nan" || param == "nanf")
			std::cout << "nanf\n";
		else if (param[0] == '-')
			std::cout << "-inff\n";
		else
			std::cout << "inff\n";
	}
	else
	{
		std::cout << static_cast<float>(value) << "f\n";
	}

	std::cout << "double: "; // DOUBLE handler
	if (isImpossible || std::isnan(value) || value < INT_MIN || value > INT_MAX)
		std::cout << "impossible\n";
	else if (isPseudoLiteral(param))
	{
		if (param == "nan" || param == "nanf")
			std::cout << "nan\n";
		else if (param[0] == '-')
			std::cout << "-inf\n";
		else
			std::cout << "inf\n";
	}
	else
	{
		std::cout << static_cast<double>(value) << "\n";
	}
}