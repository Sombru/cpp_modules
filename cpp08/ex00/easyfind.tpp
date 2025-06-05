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
void easyfind(T container, int i)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), i);
	if (it == container.end())
	{
		(std::cerr << "No value in that possition\n");
		return ;
	}
	else
		std::cout << "Found the value: " << i << " in the position > "
				  << std::distance(container.begin(), it) << '\n';
}
