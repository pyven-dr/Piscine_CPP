#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstdlib>
#include <vector>
#include <deque>

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe(void);

		void FillClass(int argc, char **argv);

		void SortVector(void);
		void DisplayVector(std::ostream& os) const;

		void SortDeque(void);

	private:
		size_t size;
		std::vector<int> vector;
		std::deque<int> deque;
};

std::ostream& operator<<(std::ostream& os, const PmergeMe& SortClass);

void InsertSortVector(std::vector<int> *vector, size_t middle);
size_t FindPos(const std::vector<int> &SortedVector, int elem);
void MergeSortVector(std::vector<int> *vector, size_t middle);

void InsertSortDeque(std::deque<int> *deque, size_t middle);
size_t FindPos(const std::deque<int> &SortedDeque, int elem);
void MergeSortDeque(std::deque<int> *deque, size_t middle);

#endif
