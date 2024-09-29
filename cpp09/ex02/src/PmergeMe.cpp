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
	size_t middle = this->size / 2;
	int temp;
	std::vector<int>::iterator itStart = this->vector.begin();
	std::vector<int>::iterator itMiddle = this->vector.begin() + middle;

	for (size_t i = 0; i < middle; ++i)
	{
		if (*itStart < *itMiddle)
		{
			temp = *itStart;
			*itStart = *itMiddle;
			*itMiddle = temp;
		}
		++itStart;
		++itMiddle;
	}
	InsertSortVector(&this->vector, middle);
	MergeSortVector(&this->vector, middle);
}

void PmergeMe::SortDeque()
{
	size_t middle = this->size / 2;
	int temp;
	std::deque<int>::iterator itStart = this->deque.begin();
	std::deque<int>::iterator itMiddle = this->deque.begin() + middle;

	for (size_t i = 0; i < middle; ++i)
	{
		if (*itStart < *itMiddle)
		{
			temp = *itStart;
			*itStart = *itMiddle;
			*itMiddle = temp;
		}
		++itStart;
		++itMiddle;
	}
	InsertSortDeque(&this->deque, middle);
	MergeSortDeque(&this->deque, middle);
}

void PmergeMe::DisplayVector(std::ostream &os) const
{
	for (std::vector<int>::const_iterator it = this->vector.begin();
		it != this->vector.end(); ++it)
		os << *it << " ";
	os << std::endl;
}

std::ostream& operator<<(std::ostream& os, const PmergeMe& SortClass)
{
	SortClass.DisplayVector(os);
	return (os);
}
