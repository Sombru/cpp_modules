#include <vector>
#include <iostream>

int main()
{
	std::vector<int> numbers;

	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);

	std::vector<int>::iterator it;

	for (it = numbers.begin(); it != numbers.end(); it++)
	{
		std::cout << *it << '\n';
	}

	return 0;
}