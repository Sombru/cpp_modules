#include "PmergeMe.hpp"

int main(int argc, char  *argv[])
{
	PmergeMe pm(argv, argc);

	(void)argc;
	pm.parseInput();	
}