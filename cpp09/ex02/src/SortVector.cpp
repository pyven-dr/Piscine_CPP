#include <cstdlib>
#include <vector>
#include <iostream>
static void InsertSortVector(std::vector<int> *vector, size_t middle)
{
	int elem;
	int elemMiddle;
	size_t j;

	std::cout << (*vector)[middle - 1 + middle] << std::endl;
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

static size_t FindPos(const std::vector<int> &SortedVector, int elem, size_t pair)
{
	size_t left = 0;
	size_t middle;

	while (left < pair)
	{
		middle = left + (pair - left) / 2;
		if (SortedVector[middle] < elem)
			left = middle + 1;
		else
			pair = middle;
	}
	return (left);
}

static void MergeSortVector(std::vector<int> *vector, size_t middle)
{
	std::vector<int> SortedVector;
	size_t i = 0;
	size_t pos;

	for ((void)i; i < middle; ++i)
		SortedVector.push_back((*vector)[i]);
	SortedVector.insert(SortedVector.begin(), (*vector)[i]);
	++i;
	for ((void)i; i < (vector->size() - 1); i++)
	{
		if (i + 1 != vector->size())
			pos = FindPos(SortedVector, (*vector)[i], i - middle);
		else
			pos = FindPos(SortedVector, (*vector)[i], SortedVector.size());
		SortedVector.insert(SortedVector.begin() + pos, (*vector)[i]);
	}
	(*vector) = SortedVector;
}

void MergeInsertSortVector(std::vector<int> *vector)
{
	size_t middle = (*vector).size() / 2;
	int temp;
	std::vector<int>::iterator itStart = (*vector).begin();
	std::vector<int>::iterator itMiddle = (*vector).begin() + middle;
	std::vector<int> Smallervector;

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
	InsertSortVector(vector, middle);
	Smallervector.assign((*vector).begin() + middle, (*vector).end());
	if (Smallervector.size() > 1)
	{
		MergeInsertSortVector(&Smallervector);
		std::copy(Smallervector.begin(), Smallervector.end(), (*vector).begin() + middle);
	}
	MergeSortVector(vector, middle);
}
