#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer &copy)
{
	static_cast<void>(copy);
}

Serializer &Serializer::operator=(const Serializer &other)
{
	static_cast<void>(other);
	return (*this);
}

Serializer::~Serializer(void) {}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
