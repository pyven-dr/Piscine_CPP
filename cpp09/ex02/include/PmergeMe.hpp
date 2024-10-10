#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstdlib>
#include <vector>
#include <deque>
#include <iostream>

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
		void DisplayDeque(std::ostream& os) const;

		void SortDeque(void);

	private:
		size_t size;
		std::vector<int> vector;
		std::deque<int> deque;
};

std::ostream& operator<<(std::ostream& os, const PmergeMe& SortClass);

void MergeInsertSortVector(std::vector<int> *vector);
void MergeInsertSortDeque(std::deque<int> *deque);
size_t JacobsthalNumbers(size_t n);

#endif
