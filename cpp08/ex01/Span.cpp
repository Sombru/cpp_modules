#include "Span.hpp"

// default constructor
Span::Span()
	: m_spanSize(0), reset(false)
{
}

Span::Span(unsigned int N)
	: m_spanSize(N), reset(false)
{
	this->data = new int[N](); // value-initialize all elements to 0
}

Span::Span(const Span &other)
	: m_spanSize(other.m_spanSize), reset(false)
{
	for (unsigned int i = 0; i < m_spanSize; i++)
	{
		addNumber(other[i]);
	}
}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return *this;
	this->m_spanSize = other.m_spanSize;
	reset = true;
	for (unsigned int i = 0; i < m_spanSize; i++)
	{
		this->addNumber(other[i]);
	}
	return *this;
}

int &Span::operator[](const unsigned int index) const
{
	return this->data[index];
}

Span::~Span()
{
	delete[] data;
}

void Span::addNumber(int number)
{
	static int i = 0;
	if (reset == true)
	{
		i = 0;
		reset = false;
	}
	this->data[i] = number;
	i++;
}

// shortestSpan: Find the smallest difference between any two numbers in array.
// longestSpan: Find the largest difference between the smallest and largest numbers in array.

unsigned int Span::shortestSpan() const
{
	if (m_spanSize < 2)
		throw std::runtime_error("Not enough elements for a span");

	// Copy data to a vector and sort it
	std::vector<int> tmp(data, data + m_spanSize);
	std::sort(tmp.begin(), tmp.end());

	unsigned int minSpan = static_cast<unsigned int>(std::abs(tmp[1] - tmp[0]));
	for (unsigned int i = 1; i < m_spanSize - 1; ++i)
	{
		unsigned int span = static_cast<unsigned int>(std::abs(tmp[i + 1] - tmp[i]));
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

unsigned int Span::longestSpan() const
{
	if (m_spanSize < 2)
		throw std::runtime_error("Not enough elements for a span");

	int minVal = *std::min_element(data, data + m_spanSize);
	int maxVal = *std::max_element(data, data + m_spanSize);

	return static_cast<unsigned int>(maxVal - minVal);
}

void Span::fillWithRandomNumbers()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	for (unsigned int i = 0; i < m_spanSize; i++)
	{
		this->addNumber(std::rand());
	}
}