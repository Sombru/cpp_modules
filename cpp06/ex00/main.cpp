#include "ScalarConverter.hpp"

// convert() takes a string as an argumnet and converts it into one of these 
// • char
// • int
// • float
// • double 
// and prints it to stdout

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "only 1 argument is allowed\n";
		return 1;
	}
	ScalarConverter::convert(argv[1]);
}