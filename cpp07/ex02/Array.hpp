#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>
#include <iostream>
#include <exception>

template<typename T>
class Array
{
private:
	T *mArray;
	unsigned int mSize;
public:
	Array();
	Array(unsigned int size);
	Array(const Array &other);
	Array &operator=(const Array &other);
	T &operator[](unsigned int index);
	~Array();

	unsigned int getSize() const;

	class OutOfRange
	: public std::exception 
	{
    	const char *what() const throw()
		{
			return "Index out of range";
		};
  	};
};

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
	if (this->mArray)
		delete[] this->mArray;
	mSize = other.getSize();
	this->mArray = new T[mSize];
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

# endif