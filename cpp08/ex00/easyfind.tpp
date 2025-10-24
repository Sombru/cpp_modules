// a container is a class or data structure that stores a collection of objects (elements).
// std::vector (dynamic array)
// std::list (doubly linked list)
// std::deque (double-ended queue)
// std::set (sorted unique elements)
// std::map (key-value pairs)
// std::stack, std::queue, etc.

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

template <typename T>
int easyfind(T container, int i)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), i);
	if (it == container.end())
		throw std::out_of_range("nuh uh");
	return *it;	
}
