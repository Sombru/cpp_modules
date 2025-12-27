#pragma once

#include <iostream>
#include <string>
#include <vector>

// template <typename T>
struct Pair
{
	int low, high;
	Pair(int a, int b) :low(a), high(b) {};
};

class PmergeMe
{
private:
	char **m_input;
	int m_size;
	std::vector<int> vec;

public:
	PmergeMe(char **argv, int argc);
	~PmergeMe();

	int parseInput();
	int sort();
	void print();
	template <typename T>
	void print_vec(const std::vector<T> &vec);
	
	std::vector<size_t> fordJohnsonOrder(size_t n);
	std::vector<std::pair<int, int> > makePairs(std::vector<int> &v, int *oddValue);
	int fordJohnsonSort(std::vector<int> &v);
};
