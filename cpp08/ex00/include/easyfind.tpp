#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, const int integer)
{
	typename T::iterator it = std::find(container.begin(), container.end(), integer);
	return (it);
}

template <typename T>
const typename T::const_iterator easyfind(const T& container, const int integer)
{
	const typename T::const_iterator it = std::find(container.begin(), container.end(), integer);
	return (it);
}


#endif