#ifndef ARRAY_TPP
# define ARRAY_TPP

#include <iostream>
#include <exception>
#include "Array.hpp"

template<typename T>
Array<T>::Array() : array_size(0), array(NULL)
{
}

template<typename T>
Array<T>::Array(unsigned int n) : array_size(n), array(new T[n]())
{
}

template<typename T>
Array<T>::Array(const Array<T> &copy) : array_size(copy.array_size), array(new T[this->array_size]())
{
	for (unsigned int i = 0; i < this->array_size; i++)
		this->array[i] = copy.array[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this == &other)
		return (*this);
	this->array_size = other.array_size;
	delete[] this->array;
	this->array = new T[this->array_size]();
	for (unsigned int i = 0; i < this->array_size; i++)
		this->array[i] = other.array[i];
	return (*this);
}

template<typename T>
Array<T>::~Array(void)
{
	delete[] this->array;
}

template<typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->array_size)
		throw std::exception();
	return (this->array[index]);
}

template<typename T>
unsigned int Array<T>::size(void)
{
	return (this->array_size);
}

template<typename T>
void Array<T>::printArray(void)
{
	for (unsigned int i = 0; i < this->array_size; i++)
		std::cout << this->array[i] << " ";
	std::cout << std::endl;
}

#endif