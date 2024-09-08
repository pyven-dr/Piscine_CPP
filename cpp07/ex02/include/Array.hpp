#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& copy);
		Array& operator=(const Array& other);
		~Array(void);

		unsigned int size(void);
		void printArray(void);
		T& operator[](unsigned int index);

	private:
		unsigned int array_size;
		T* array;
};

#include "Array.tpp"
#endif