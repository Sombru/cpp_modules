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

#include "Array.tpp"

# endif