#include <vector>
#include <set>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vector;
	vector.push_back(5);
	vector.push_back(7);
	vector.push_back(8);
	vector.push_back(1);
	vector.push_back(5);

	std::vector<int>::iterator it = easyfind(vector, 5);
	if (it != vector.end())
		std::cout << "found at index " << std::distance(vector.begin(), it) << std::endl;
	else
		std::cout << "Element not found" << std::endl;

	it = easyfind(vector, 6);
	if (it != vector.end())
		std::cout << "found at index " << std::distance(vector.begin(), it) << std::endl;
	else
		std::cout << "Element not found" << std::endl;

	std::set<int> set;
	set.insert(6);
	set.insert(4);
	set.insert(8);
	set.insert(7);
	set.insert(2);

	std::set<int>::iterator it_set = easyfind(set, 7);
	if (it_set != set.end())
		std::cout << "found at index " << std::distance(set.begin(), it_set) << std::endl;
	else
		std::cout << "Element not found" << std::endl;

	it_set = easyfind(set, 10);
	if (it_set != set.end())
		std::cout << "found at index " << std::distance(set.begin(), it_set) << std::endl;
	else
		std::cout << "Element not found" << std::endl;
	return (0);
}