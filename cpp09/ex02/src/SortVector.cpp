#include <cstdlib>
#include <vector>

void InsertSortVector(std::vector<int> *vector, size_t middle)
{
	int elem;
	int elemMiddle;
	size_t j;

	for (size_t i = 1; i < middle; ++i)
	{
		elem = (*vector)[i];
		elemMiddle = (*vector)[i + middle];
		j = i;
		while(j > 0 && (*vector)[j - 1] > elem)
		{
			(*vector)[j] = (*vector)[j - 1];
			(*vector)[j + middle] = (*vector)[j - 1 + middle];
			--j;
		}
		(*vector)[j] = elem;
		(*vector)[j + middle] = elemMiddle;
	}
}

size_t FindPos(const std::vector<int> &SortedVector, int elem)
{
	size_t left = 0;
	size_t right = SortedVector.size();
	size_t middle;

	while (left < right)
	{
		middle = left + (right - left) / 2;
		if (SortedVector[middle] < elem)
			left = middle + 1;
		else
			right = middle;
	}
	return (left);
}

void MergeSortVector(std::vector<int> *vector, size_t middle)
{
	std::vector<int> SortedVector;
	size_t i = 0;
	size_t pos;

	for ((void)i; i < middle; ++i)
		SortedVector.push_back((*vector)[i]);
	SortedVector.insert(SortedVector.begin(), (*vector)[i]);
	++i;
	for ((void)i; i < vector->size(); i++)
	{
		pos = FindPos(SortedVector, (*vector)[i]);
		SortedVector.insert(SortedVector.begin() + pos, (*vector)[i]);
	}
	(*vector) = SortedVector;
}
