#include "PmergeMe.hpp"
#include <sstream>
#include <stdlib.h>

PmergeMe::PmergeMe(char **argv, int argc)
	: m_input(&argv[1]), m_size(argc - 1) // , vec(m_size)
{
}

PmergeMe::~PmergeMe()
{
}

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

int PmergeMe::sort()
{
	fordJohnsonSort(this->vec);
	return 0;
}

void PmergeMe::print()
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << "vec[" << i << "]: " << vec[i] << "\n";
	}
	
}

std::vector<size_t> PmergeMe::fordJohnsonOrder(size_t n)
{
	std::vector<size_t> order;
	if (n == 0)
		return order;

	// Jacobsthal numbers
	std::vector<size_t> jacob;
	jacob.push_back(1);
	jacob.push_back(3);

	while (jacob.back() < n)
		jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);

	size_t prev = 0;
	for (size_t k = 0; k < jacob.size(); ++k)
	{
		size_t end = std::min(jacob[k], n);
		for (size_t i = end; i-- > prev;)
			order.push_back(i);
		prev = end;
		if (prev >= n)
			break;
	}


	return order;
}

void binaryInsert(std::vector<int> &arr, int value, size_t upperBound)
{
	size_t left = 0;
	size_t right = upperBound;

	while (left < right)
	{
		size_t mid = (left + right) / 2;
		if (value < arr[mid])
			right = mid;
		else
			left = mid + 1;
	}
	arr.insert(arr.begin() + left, value);
}

int PmergeMe::fordJohnsonSort(std::vector<int> &v)
{
	if (v.size() <= 1)
		return 1;

	// STEP 1: Pair elements
	std::vector<std::pair<int, int> > pairs;
    size_t i = 0;
	for (; i + 1 < v.size(); i += 2)
	{
		if (v[i] < v[i + 1]) // sort them immidietly
			pairs.push_back(std::make_pair(v[i], v[i + 1]));
		else
			pairs.push_back(std::make_pair(v[i + 1], v[i]));
	}

    // Handle odd element
    bool hasOdd = (i < v.size());
    int oddValue = 0;
	if (hasOdd)
		oddValue = v[i];
	
	// STEP 2: Extract winners (U)
	std::vector<int> U;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		U.push_back(pairs[i].second);
	}

	// Recursively sort U
	fordJohnsonSort(U);

	// STEP 3: Insert losers (L)
	std::vector<int> L = U;

	// Generate insertion order
	std::vector<size_t> order = fordJohnsonOrder(pairs.size());

	for (size_t k = 0; k < order.size(); ++k)
	{
		size_t idx = order[k];
		int loser = pairs[idx].first;
		int winner = pairs[idx].second;

		// Find winner position in L
		size_t upperBound = 0;
		while (upperBound < L.size() && L[upperBound] != winner)
			++upperBound;

		binaryInsert(L, loser, upperBound);
	}

	// STEP 4: Insert odd element if present
	if (hasOdd)
	{
		binaryInsert(L, oddValue, L.size());
	}

	v = L;
	return 0;
}