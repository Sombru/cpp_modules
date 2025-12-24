#include "PmergeMe.hpp"
#include <sstream>
#include <stdlib.h>

PmergeMe::PmergeMe(char **argv, int argc)
	: m_input(&argv[1]), m_size(argc - 1)// , vec(m_size)
{}

PmergeMe::~PmergeMe()
{}

int PmergeMe::parseInput()
{
	vec.reserve(m_size);
	for (int i = 0; i < (m_size); ++i)
	{
		vec.push_back(std::atoi(m_input[i]));
		// std::cout << vec[i] << std::endl;
	}
	return 0;
}

int PmergeMe::MergeInsert()
{
	makePairs();
	sortPairs();
	return 0;
}

int PmergeMe::makePairs()
{
	pairs.reserve(m_size + 1);

	for (size_t i = 0; i < vec.size(); i+=2)
	{
		std::pair<int, int> pair;

		pair.first = vec[i];
		pair.second = vec[i+1];
		pairs.push_back(pair);
		// i/2 to get index of "pairs"
		// std::cout << "pairs[" << i/2 << "].first: "<<  pairs[i/2].first << std::endl;
		// std::cout << "pairs[" << i/2 << "].second: "<< pairs[i/2].second << std::endl;
	}
	return 0;	
}


int PmergeMe::sortPairs()
{
	std::cout << "HERE, " << pairs.size() << "\n";
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].first > pairs[i].second)
		{
			// std::cout << "before swap: " << pairs[i].first << ',' << pairs[i].second << std::endl;
			int tmp = pairs[i].first;
			pairs[i].first = pairs[i].second;
			pairs[i].second = tmp;
			// std::cout << "after swap: " << pairs[i].first << ',' << pairs[i].second << std::endl;
		}
	}
	return 0;
}