#include "BitcoinExchange.hpp"

int main()
{
	BitcoinExchange b;

	if (b.readData("data.csv"))
		b.printError("could not read \"data.csv\" file\n");
	if (b.readInput("input.txt"))
		b.printError("could not read \"input.txt\" file\n");
}