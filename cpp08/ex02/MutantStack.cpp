#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::iterator::iterator(T *ptr)
	: it_ptr(ptr)
{
}

template <typename T>
MutantStack<T>::iterator::iterator(const iterator &other)
{
	this = &other; 
}

template <typename T>
MutantStack<T>::iterator::~iterator()
{
}