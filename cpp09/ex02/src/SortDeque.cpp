#include <cstdlib>
#include <deque>

void InsertSortDeque(std::deque<int> *deque, size_t middle)
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

size_t FindPos(const std::deque<int> &SortedDeque, int elem)
{
	size_t left = 0;
	size_t right = SortedDeque.size();
	size_t middle;

	while (left < right)
	{
		middle = left + (right - left) / 2;
		if (SortedDeque[middle] < elem)
			left = middle + 1;
		else
			right = middle;
	}
	return (left);
}

void MergeSortDeque(std::deque<int> *deque, size_t middle)
{
	std::deque<int> SortedDeque;
	size_t i = 0;
	size_t pos;

	for ((void)i; i < middle; ++i)
		SortedDeque.push_back((*deque)[i]);
	SortedDeque.insert(SortedDeque.begin(), (*deque)[i]);
	++i;
	for ((void)i; i < deque->size(); i++)
	{
		pos = FindPos(SortedDeque, (*deque)[i]);
		SortedDeque.insert(SortedDeque.begin() + pos, (*deque)[i]);
	}
	(*deque) = SortedDeque;
}
