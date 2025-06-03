#include "iter.hpp"
#include <iostream>
#include <string>

void printInt(int x)
{
    std::cout << x << " ";
}

void printString(const std::string& s)
{
    std::cout << s << " ";
}

void increment(int &x)
{
	x += 5;
}

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	std::string strs[] = {"hello", "world", "template"};

	std::cout << "Print int array: ";
	iter(arr, 5, printInt);
	std::cout << '\n';

	std::cout << "Increment int array: ";
	iter(arr, 5, increment);
	iter(arr, 5, printInt);
	std::cout << '\n';

	std::cout << "Print string array: ";
	iter(strs, 3, printString);
	std::cout << '\n';

	return 0;
}