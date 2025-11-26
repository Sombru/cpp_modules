#include "BitcoinExchange.hpp"
#include "Date.hpp"

int main()
{
	BitcoinExchange b;
	Date d;

	if (b.readData("data.csv"))
		b.logError("could not read \"data.csv\" file\n");
	if (b.readInput("input.txt"))
		b.logError("could not read \"input.txt\" file\n");
	
	// if (b.parseInput())
	// b.logDebug(d.to_string(d.to_time_t("2026-04-05")));
	b.parseInput();
	b.parseData();
	b.calculate();
}