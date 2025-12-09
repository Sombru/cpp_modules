#pragma once

#include <iostream>

enum operators
{
	PLUS,
	MINUS,
	DIVIDE,
	MULTIPLY
};


struct vars
{
	int a;
	int b;
	operators c;
};

class RPN
{
private:
	std::string m_input;

public:
	RPN(std::string m_input);
	~RPN();
	int parseInput();
};

