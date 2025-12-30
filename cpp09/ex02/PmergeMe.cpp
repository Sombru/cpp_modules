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

int PmergeMe::size() {return this->m_size;}

int PmergeMe::parseInput()
{
	vec.reserve(m_size);
	for (int i = 0; i < (m_size); ++i)
	{			
		for (size_t j = 0; m_input[i][j]; ++j)
		{
			if (!isdigit(m_input[i][j]))
				return 1;
		}
		
		vec.push_back(std::atol(m_input[i]));
		if (vec[i] < 0)
			return 1;
		deq.push_back(std::atol(m_input[i]));
		// std::cout << vec[i] << std::endl;
	}
	return 0;
}		


int PmergeMe::sortVec()
{
	std::cout << "sorting vec\n";
	return fordJohnsonSort(this->vec);
}

int PmergeMe::sortDeq()
{
	std::cout << "sorting deq\n";
	return fordJohnsonSort(this->deq);
}


void PmergeMe::print()
{
	std::cout << "vec: ";
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << ' ';
	}
	std::cout << '\n';
	std::cout << "deq: ";

	for (size_t i = 0; i < deq.size(); ++i)
	{
		std::cout  << deq[i] << ' ';
	}
	std::cout << '\n';
}

template <typename T>
void PmergeMe::print_vec(const std::vector<T> &vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << "DEBUG:vec[" << i << "]: " << vec[i] << "\n";
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

	while (jacob.back() < n) // generate jacobs numbers up to the size of pairs (if n = 5 jabcobs.back() == 3)
    jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);// jacobs numbers recurence formula :Jn​=Jn−1​+2Jn−2

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

	// print_vec(order);
	return order;
}

// insert elemnt in sequence 
void binaryInsert(std::vector<int> &arr, int value, size_t upperBound)
{
	size_t left = 0; // offset
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
	
	// STEP 2: Extract winners (W)
	std::vector<int> W;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		W.push_back(pairs[i].second);
	}

	// Recursively sort W
	fordJohnsonSort(W);

	// STEP 3: Insert losers (L)
	std::vector<int> L = W;

	// Generate insertion order for (L)
	std::vector<size_t> order = fordJohnsonOrder(pairs.size());

	for (size_t k = 0; k < order.size(); ++k)
	{
		size_t idx = order[k]; // index of (L) to be sorted/insterted
		int loser = pairs[idx].first; // value to insert in (L) 
		int winner = pairs[idx].second; // upper bound

		// Find winner position in L
		size_t upperBound = 0;
		while (upperBound < L.size() && L[upperBound] != winner)
			++upperBound;

		binaryInsert(L, loser, upperBound);
	}

	// STEP 4: Insert odd element
	if (hasOdd)
	{
		binaryInsert(L, oddValue, L.size());
	}

	v = L;
	return 0;
}

// insert elemnt in sequence 
void binaryInsert(std::deque<int> &arr, int value, size_t upperBound)
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

int PmergeMe::fordJohnsonSort(std::deque<int> &v)
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
	
	// STEP 2: Extract winners (W)
	std::deque<int> W;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		W.push_back(pairs[i].second);
	}

	// Recursively sort W
	fordJohnsonSort(W);

	// STEP 3: Insert losers (L)
	std::deque<int> L = W;

	// Generate insertion order for (L)
	std::vector<size_t> order = fordJohnsonOrder(pairs.size());

	for (size_t k = 0; k < order.size(); ++k)
	{
		size_t idx = order[k]; // index of (L) to be sorted/insterted
		int loser = pairs[idx].first; // element in sequence
		int winner = pairs[idx].second; // upper bound

		// Find winner position in L
		size_t upperBound = 0;
		while (upperBound < L.size() && L[upperBound] != winner)
			++upperBound;

		binaryInsert(L, loser, upperBound);
	}

	// STEP 4: Insert odd element
	if (hasOdd)
	{
		binaryInsert(L, oddValue, L.size());
	}

	v = L;
	return 0;
}