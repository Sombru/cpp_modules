#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>

class Span
{
private:
	unsigned int m_spanSize;
	int *data;
	bool reset;	
public:
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	int &operator[](const unsigned int index) const;
	~Span();

	void addNumber(int);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	void fillWithRandomNumbers();
};

#endif