#include "PmergeMe.hpp"
#include <sstream>
#include <stdlib.h>

PmergeMe::PmergeMe(char **argv, int argc)
	: m_input(&input[1]), m_size(argc - 1)
{}

PmergeMe::~PmergeMe()
{}

int PmergeMe::parseInput()
{
	for (int i = 0; i < (m_size); ++i)
	{
		vec.push_back(std::atoi(m_input[i]));
		// std::cout << atoi(m_input[i]) << std::endl;
		std::cout << vec[i] << std::endl;
	}
	return 0;
}