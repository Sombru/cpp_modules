#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <deque>

// works for vector and deque 
class PmergeMe
{
private:
	char **m_input;
	int m_size;
	std::vector<int> vec;
	std::deque<int> deq;

public:
	PmergeMe(char **argv, int argc);
	~PmergeMe();

	int size();

	int parseInput();
	int sortVec();
	int sortDeq();
	void print();


	template <typename T>
	void print_vec(const std::vector<T> &vec);
	
	std::vector<size_t> fordJohnsonOrder(size_t n);
	int fordJohnsonSort(std::vector<int> &v);

	int fordJohnsonSort(std::deque<int> &v);
};
