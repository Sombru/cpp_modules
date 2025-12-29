#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN
{
private:
	std::stack<double> m_stack;

	int isOperator(const std::string &token) const;
	int isNumber(const std::string &token) const;
	int performOperation(const std::string &op);

public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	int evaluate(const std::string &expression, double &result);
};
