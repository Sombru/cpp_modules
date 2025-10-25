#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::iterator::iterator(T *ptr)
	: it_ptr(ptr)
{
}

template <typename T>
MutantStack<T>::iterator::iterator(const iterator &other)
	: it_ptr(other.it_ptr)
{
}

template <typename T>
MutantStack<T>::iterator::~iterator()
{
}

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator=(const iterator &other)
{
	if (this != &other)
	{
		this->it_ptr = other.it_ptr;
	}
	return *this;
}

template <typename T>
T &MutantStack<T>::iterator::operator*() const
{
	return *it_ptr;
}

template <typename T>
T *MutantStack<T>::iterator::operator->() const
{
	return it_ptr;
}

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator++()
{
	++it_ptr;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++(int)
{
	iterator tmp(*this);
	++(*this);
	return tmp;
}

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator--()
{
	--it_ptr;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--(int)
{
	iterator tmp(*this);
	--(*this);
	return tmp;
}

template <typename T>
bool MutantStack<T>::iterator::operator==(const iterator &other) const
{
	return it_ptr == other.it_ptr;
}

template <typename T>
bool MutantStack<T>::iterator::operator!=(const iterator &other) const
{
	return it_ptr != other.it_ptr;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return iterator(&this->c.front());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return iterator(&this->c.back() + 1);
}