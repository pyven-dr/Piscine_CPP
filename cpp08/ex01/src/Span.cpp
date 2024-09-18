#include <algorithm>
#include <limits>
#include "Span.hpp"

Span::Span(void) : N(0), NumList() {}

Span::Span(unsigned int N) : N(N), NumList() {}

Span::Span(const Span &copy) : N(copy.N), NumList(copy.NumList) {}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return (*this);
	this->N = other.N;
	this->NumList = other.NumList;
	return (*this);
}

Span::~Span() {}

const char *Span::SpanFull::what(void) const throw()
{
	return ("Not enough space to add number");
}

const char *Span::NotEnoughNumbers::what(void) const throw()
{
	return ("Not enough numbers in span");
}

void Span::addNumber(int number)
{
	if (this->NumList.size() == N)
		throw Span::SpanFull();
	this->NumList.push_back(number);
}

int Span::longestSpan(void)
{
	if (this->NumList.size() < 2)
		throw Span::NotEnoughNumbers();

	std::vector<int> tmp_vector = this->NumList;

	std::sort(tmp_vector.begin(), tmp_vector.end());
	return (tmp_vector.back() - tmp_vector.front());
}

int Span::shortestSpan(void)
{
	if (this->NumList.size() < 2)
		throw Span::NotEnoughNumbers();

	int shortestSpan = std::numeric_limits<int>::max();
	std::vector<int> tmp_vector = this->NumList;

	std::sort(tmp_vector.begin(), tmp_vector.end());
	for (std::vector<int>::iterator it = tmp_vector.begin() + 1;
		it < tmp_vector.end(); ++it)
	{
		if (*it - *(it - 1) < shortestSpan)
			shortestSpan = *it - *(it - 1);
	}
	return (shortestSpan);
}
