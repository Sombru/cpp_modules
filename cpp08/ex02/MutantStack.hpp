#pragma once
#include <stack>
#include <iostream>
#include <vector>

template <typename T>
class MutantStack
	: public std::stack<T>
{
private:
public:
	class iterator
	{
	private:
		T *it_ptr;

	public:
		iterator(T *ptr);
		iterator(const iterator &other);
		iterator &operator=(const iterator &other);
		~iterator();

		T &operator*() const;	  // dereference
		T *operator->() const;	  // member access
		iterator &operator++();	  // prefix ++
		iterator operator++(int); // postfix ++
		iterator &operator--();	  // prefix --
		iterator operator--(int); // postfix --
		bool operator==(const iterator &other) const;
		bool operator!=(const iterator &other) const;
	};

	// --- begin/end ---
	iterator begin();
	iterator end();
};

#include "MutantStack.tpp"