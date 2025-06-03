#ifndef WHATEVER_HPP
# define WHATEVER_HPP

// https://www.youtube.com/watch?v=I-hZkUa9mIs&t=34s

// template takes a whaterver specified as a paramter and replaces all instaces of
template<typename Type>
void swap(Type &a, Type &b)
{
	Type tmp = a;

	a = b;
	b = tmp;
}

template<typename T>
T min(T a, T b)
{
	if (a < b)
		return a;
	else 
		return b;
}

template<typename T>
T max(T a, T b)
{
	if (a > b)
		return a;
	else 
		return b;
}
# endif