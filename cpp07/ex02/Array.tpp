#include "Array.hpp"

template<typename T> 
Array<T>::Array()
: mSize(0)
{
	this->mArray = new T[mSize];
}

template<typename T> 
Array<T>::Array(unsigned int size)
: mSize(size)
{
	this->mArray = new T[size];
}

template<typename T> 
Array<T>::Array(const Array &other)
: mSize(other.getSize())
{
	this->mArray = new T[mSize];
	for (unsigned int i = 0; i < mSize; i++)
	{
		this->mArray[i] = other.mArray[i];
	}
}

template<typename T> 
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return *this;
	if (this->mArray)
		delete[] this->mArray;
	this->mArray = new T[other.getSize()];
	mSize = other.getSize();
	for (unsigned int i = 0; i < mSize; i++)
	{
		this->mArray[i] = other.mArray[i];
	}
	return *this;
}

template<typename T> 
Array<T>::~Array()
{
	delete[] this->mArray;
}

template<typename T> 
unsigned int Array<T>::getSize() const
{
	return this->mSize;
}

template<typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= mSize)
		throw OutOfRange();
	return this->mArray[i];
}