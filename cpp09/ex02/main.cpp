#include "PmergeMe.hpp"
#include <ctime>
#include <iostream>

int main(int argc, char *argv[])
{
	PmergeMe pm(argv, argc);

	pm.parseInput();
	pm.print();
	
	clock_t start = clock();
	pm.sort();
	clock_t end = clock();
	
	double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
	
	pm.print();
	
	std::cout << "Time to sort a sequence of: " << pm.size() << " elements, " << duration << " microseconds" << std::endl;
}