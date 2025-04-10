#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: HARL can only take 1 argument\n";
		return 1;
	}

	Harl Harl;

	Harl.complain(argv[1]);
}