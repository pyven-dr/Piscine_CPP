#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>
#include "Data.hpp"

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer(void);
		Serializer(const Serializer& copy);
		Serializer& operator=(const Serializer& other);
		~Serializer(void);
};

#endif
