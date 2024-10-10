#include <stdexcept>
#include <iostream>
#include <limits>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : size(0) {}

PmergeMe::PmergeMe(const PmergeMe &copy) : size(copy.size),
		vector(copy.vector), deque(copy.deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this == &other)
		return (*this);
	this->size = other.size;
	this->vector = other.vector;
	this->deque = other.deque;
	return (*this);
}

PmergeMe::~PmergeMe() {}

size_t JacobsthalNumbers(size_t n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return ((JacobsthalNumbers(n - 2) * 2) + JacobsthalNumbers(n - 1));
}

void PmergeMe::FillClass(int argc, char **argv)
{
	char *endptr;
	__int64_t number;

	this->size = argc - 1;
	for (int i = 1; i < argc; ++i)
	{
		number = std::strtol(argv[i], &endptr, 10);
		if (*endptr != '\0')
			throw(std::invalid_argument("Numeric arguments required"));
		if (number > std::numeric_limits<int>::max() || number < 0)
			throw(std::invalid_argument("Arguments needs to be positive integers"));
		this->vector.push_back(static_cast<int>(number));
		this->deque.push_back(static_cast<int>(number));
	}
}


void PmergeMe::SortVector()
{
	MergeInsertSortVector(&this->vector);
}

void PmergeMe::SortDeque()
{
	MergeInsertSortDeque(&this->deque);
}

void PmergeMe::DisplayVector(std::ostream &os) const
{
	for (std::vector<int>::const_iterator it = this->vector.begin();
		it != this->vector.end(); ++it)
		os << *it << " ";
	os << std::endl;
}

void PmergeMe::DisplayDeque(std::ostream &os) const
{
	for (std::deque<int>::const_iterator it = this->deque.begin();
		 it != this->deque.end(); ++it)
		os << *it << " ";
	os << std::endl;
}

std::ostream& operator<<(std::ostream& os, const PmergeMe& SortClass)
{
	SortClass.DisplayVector(os);
	return (os);
}
