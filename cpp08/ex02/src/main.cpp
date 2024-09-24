#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top " << mstack.top() << std::endl;
	std::cout << "Size " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "Top " << mstack.top() << std::endl;
	std::cout << "Size " << mstack.size() << "\n" << std::endl;

	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Iterator mutant stack" << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "\nReverse Iterator mutant stack" << std::endl;

	MutantStack<int>::reverse_iterator rev_it = mstack.rbegin();
	MutantStack<int>::reverse_iterator rev_ite = mstack.rend();
	++rev_it;
	--rev_it;
	while (rev_it != rev_ite)
	{
		std::cout << *rev_it << std::endl;
		++rev_it;
	}

	std::stack<int> s(mstack);


	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::cout << "\nIterator list" << std::endl;

	std::list<int>::iterator list_it = list.begin();
	std::list<int>::iterator list_ite = list.end();
	++list_it;
	--list_it;
	while (list_it != list_ite)
	{
		std::cout << *list_it << std::endl;
		++list_it;
	}

	std::cout << "\nReverse Iterator list" << std::endl;

	std::list<int>::reverse_iterator list_rev_it = list.rbegin();
	std::list<int>::reverse_iterator list_rev_ite = list.rend();
	++list_rev_it;
	--list_rev_it;
	while (list_rev_it != list_rev_ite)
	{
		std::cout << *list_rev_it << std::endl;
		++list_rev_it;
	}
	return 0;
}
