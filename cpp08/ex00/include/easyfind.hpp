#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template<typename T>
typename T::iterator easyfind(T& container, int integer);

template<typename T>
const typename T::const_iterator easyfind(const T& container, int integer);

#include "easyfind.tpp"

#endif