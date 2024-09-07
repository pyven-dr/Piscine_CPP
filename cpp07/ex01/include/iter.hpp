#ifndef ITER_HPP
# define ITER_HPP

#include <cstdlib>

template<typename Array>
void iter(Array *array, const size_t lenght, void (*f)(Array&))
{
	if (array == NULL || f == NULL)
		return;
	for (size_t i = 0; i < lenght; i++)
		f(array[i]);
}

template<typename Array>
void iter(const Array *array, const size_t lenght, void (*f)(const Array&))
{
	if (array == NULL || f == NULL)
		return;
	for (size_t i = 0; i < lenght; i++)
		f(array[i]);
}

#endif
