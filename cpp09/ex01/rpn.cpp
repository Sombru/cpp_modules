#include "rpn.hpp"

RPN::RPN() : m_stack()
{
}

RPN::RPN(const RPN &other) : m_stack(other.m_stack)
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		m_stack = other.m_stack;
	}
	return *this;
}

RPN::~RPN()
{
}

int RPN::isOperator(const std::string &token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::isNumber(const std::string &token) const
{
	if (token.empty())
		return 0;

	size_t start = 0;
	if (token[0] == '-' || token[0] == '+')
	{
		if (token.length() == 1)
			return 0;
		start = 1;
	}

	bool hasDot = false;
	for (size_t i = start; i < token.length(); i++)
	{
		if (token[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (!std::isdigit(token[i]))
			return false;
	}
	return true;
}

int RPN::performOperation(const std::string &op)
{
	if (m_stack.size() < 2)
	{
		std::cerr << "Error: insufficient operands" << std::endl;
		return false;
	}

	double b = m_stack.top();
	m_stack.pop();
	double a = m_stack.top();
	m_stack.pop();

	double result;
	if (op == "+")
		result = a + b;
	else if (op == "-")
		result = a - b;
	else if (op == "*")
		result = a * b;
	else if (op == "/")
	{
		if (b == 0)
		{
			std::cerr << "Error: division by zero" << std::endl;
			return false;
		}
		result = a / b;
	}
	else
	{
		std::cerr << "Error: unknown operator" << std::endl;
		return false;
	}

	m_stack.push(result);
	return true;
}

int RPN::evaluate(const std::string &expression, double &result)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (isNumber(token))
		{
			double num = std::atof(token.c_str());
			m_stack.push(num);
		}
		else if (isOperator(token))
		{
			if (!performOperation(token))
				return false;
		}
		else
		{
			std::cerr << "Error: invalid token" << std::endl;
			return false;
		}
	}

	if (m_stack.size() != 1)
	{
		std::cerr << "Error: invalid expression" << std::endl;
		return false;
	}

	result = m_stack.top();
	return true;
}