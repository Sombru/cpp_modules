#ifndef ITER_HPP
# define ITER_HPP

#include <string>
#include <iostream>
// https://www.youtube.com/watch?v=I-hZkUa9mIs&t=34s

// template takes a whaterver specified as a paramter and replaces all instaces of
template<typename Type, typename Args>
void iter(Type *ptr, int size, void (*foo)(Args))
{
	for (int i = 0; i < size; i++)
	{
		foo(ptr[i]);
	}
}


# endif