#include <deque>
#include "PmergeMe.hpp"

static void InsertSortDeque(std::deque<int> *deque, size_t middle)
{
	int elem;
	int elemMiddle;
	size_t j;

	for (size_t i = 1; i < middle; ++i)
	{
		elem = (*deque)[i];
		elemMiddle = (*deque)[i + middle];
		j = i;
		while(j > 0 && (*deque)[j - 1] > elem)
		{
			(*deque)[j] = (*deque)[j - 1];
			(*deque)[j + middle] = (*deque)[j - 1 + middle];
			--j;
		}
		(*deque)[j] = elem;
		(*deque)[j + middle] = elemMiddle;
	}
}

static size_t FindPos(const std::deque<int> &SortedDeque, int elem, size_t pair)
{
	size_t left = 0;
	size_t middle;

	while (left < pair)
	{
		middle = left + (pair - left) / 2;
		if (SortedDeque[middle] < elem)
			left = middle + 1;
		else
			pair = middle;
	}
	return (left);
}

static void MergeSortDeque(std::deque<int> *deque)
{
	std::deque<int> SortedDeque;
	size_t i = 0;
	size_t pos;
	size_t middle = (*deque).size() / 2;

	for ((void)i; i < middle; ++i)
		SortedDeque.push_back((*deque)[i]);
	SortedDeque.insert(SortedDeque.begin(), (*deque)[i]);
	++i;
	for (size_t j = 0; JacobsthalNumbers(j) < deque->size(); ++j)
	{
		size_t number = JacobsthalNumbers(j);
		middle = (*deque).size() / 2;

		if (number > middle)
		{
			pos = FindPos(SortedDeque, (*deque)[number], SortedDeque.size());
			SortedDeque.insert(SortedDeque.begin() + pos, (*deque)[number]);
			deque->erase(deque->begin() + number);
		}
	}
	for ((void)i; i < deque->size(); i++)
	{
		pos = FindPos(SortedDeque, (*deque)[i], SortedDeque.size());
		SortedDeque.insert(SortedDeque.begin() + pos, (*deque)[i]);
	}
	(*deque) = SortedDeque;
}

void MergeInsertSortDeque(std::deque<int> *deque)
{
	size_t middle = (*deque).size() / 2;
	int temp;
	std::deque<int>::iterator itStart = (*deque).begin();
	std::deque<int>::iterator itMiddle = (*deque).begin() + middle;
	std::deque<int> SmallerDeque;

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
	InsertSortDeque(deque, middle);
	SmallerDeque.assign((*deque).begin() + middle, (*deque).end());
	if (SmallerDeque.size() > 1)
	{
		MergeInsertSortDeque(&SmallerDeque);
		std::copy(SmallerDeque.begin(), SmallerDeque.end(), (*deque).begin() + middle);
	}
	MergeSortDeque(deque);
}
