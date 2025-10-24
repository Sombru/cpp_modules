#include <vector>
#include <iostream>
#include "easyfind.tpp"
#include <set>

// https://www.youtube.com/watch?v=Xx-NcqmveDc good vid
int main()
{
	std::vector<int> numbers;
	// std::vector<int> numbers(x); can give it a size priemtevly

	// its all heap allocation
	numbers.push_back(10); 
	numbers.push_back(20);
	numbers.push_back(30);
	
	std::vector<int>::iterator it;
	
	for (it = numbers.begin(); it != numbers.end(); it++)
	{
		std::cout << *it << '\n';
	}
	std::cout << "Found the value: " << easyfind(numbers, 10) << "\n";

	std::set<int> set;

	set.insert(4);
	set.insert(4);
	set.insert(8);
	std::cout << "Found the value: " << easyfind(set, 7) << "\n";

}