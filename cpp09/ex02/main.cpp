#include "PmergeMe.hpp"
#include <ctime>
#include <iostream>

int main(int argc, char *argv[])
{
	PmergeMe pm(argv, argc);

	if (pm.parseInput())
	{
		std::cerr << "Error\n";
		return 1;
	}
	pm.print();
	
	clock_t start = clock();
	if (pm.sortVec())
	{
		std::cerr << "Error\n";
		return 1;
	}
	clock_t end = clock();
	
	double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
	
	std::cout << "Time to sort a vector of: " << pm.size() << " elements, " << duration << " microseconds" << std::endl;

	pm.print();

	start = clock();

	if (pm.sortDeq())
	{
		std::cerr << "Error\n";
		return 1;
	}

	end = clock();

	duration = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Time to sort a deque of: " << pm.size() << " elements, " << duration << " microseconds" << std::endl;

	pm.print();
}

// deque will be slower since it uses multiple memmoves to exapnd and multiple block layout can trigger cache miss

// vector layout
// [ 1 ][ 2 ][ 3 ][ 4 ][ 5 ][ 6 ][ 7 ]

// deque layout 
// [ 1 ][ 2 ][ 3 ] -> [ 4 ][ 5 ][ 6 ] -> [ 7 ]
    //   block 0          block 1          block 2