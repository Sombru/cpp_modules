#include "BitcoinExchange.hpp"
#include "Date.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Bad number of arguments\n";
		return 1;
	}
	BitcoinExchange b;

	if (b.readData("data.csv"))
		b.logError("could not read \"data.csv\" file\n");
	if (b.readInput(argv[1]))
		b.logError("could not read " + std::string(argv[1]) + " file\n");
	
	// if (b.parseInput())
	// b.logDebug(d.to_string(d.to_time_t("2026-04-05")));
	b.parseInput();
	b.parseData();
	b.calculate();
}