#include "rpn.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Bad number of arguments\n";
		return 1;
	}

	RPN rpn(argv[1]);
	
}