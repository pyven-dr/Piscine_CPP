#include <cstdlib>
#include <sstream>
#include <iostream>
#include "RPN.hpp"

RPN::RPN() : stack() {}

RPN::RPN(const RPN &copy) : stack(copy.stack) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		this->stack = other.stack;
	return (*this);
}

RPN::~RPN() {}

int RPN::addNumber(const std::string &str_number)
{
	int number = checkNumber(str_number);

	if (number == -1)
		return (-1);
	this->stack.push(number);
	return (0);
}

__int64_t RPN::PopAndGet(void)
{
	__int64_t number = this->stack.top();
	this->stack.pop();
	return (number);
}

int RPN::calculate(const std::string &strOperator)
{
	char Operator;
	__int64_t result;

	if (checkOperator(strOperator) == -1)
	{
		std::cerr << "Invalid operator " << strOperator << std::endl;
		return (-1);
	}
	if (this->stack.size() < 2)
	{
		std::cerr << "Unexpected operator " << strOperator << std::endl;
		return (-1);
	}
	Operator = strOperator[0];
	result = makeOperation(Operator, this->PopAndGet(), this->PopAndGet());
	if (result == -1)
		return (-1);
	this->stack.push(result);
	return (0);
}

void RPN::resolve(const std::string &operation)
{
	std::stringstream stream(operation);
	std::string token;

	while (std::getline(stream, token, ' '))
	{
		if (std::isdigit(token[0]) != 0)
		{
			if (this->addNumber(token) == -1)
				return;
		}
		else
		{
			if (this->calculate(token) == -1)
				return;
		}
	}
	if (this->stack.size() > 1)
	{
		std::cerr << "Incomplete expression" << std::endl;
		return;
	}
	if (this->stack.empty() == false)
		std::cout << this->PopAndGet() << std::endl;
}
