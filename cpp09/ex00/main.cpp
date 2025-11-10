#include "BitcoinExchange.hpp"

int main()
{
	BitcoinExchange b;

	if (b.readData("data.csv"))
		b.logError("could not read \"data.csv\" file\n");
	if (b.readInput("input.txt"))
		b.logError("could not read \"input.txt\" file\n");
	
	if (b.parseInput())
}