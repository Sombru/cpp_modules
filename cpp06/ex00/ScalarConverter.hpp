#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP

#include <iostream>

// A type that holds a single value of a defined range.
// Scalars include arithmetic types (integral or floating-point values),
// enumeration type members, pointer types, pointer-to-member types, and std::nullptr_t .

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other); 
	~ScalarConverter();
public:

	static void convert(const std::string &param);
};

# endif