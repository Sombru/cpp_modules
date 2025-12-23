#pragma once

#include <iostream>
#include <string>
#include <vector>

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
};

