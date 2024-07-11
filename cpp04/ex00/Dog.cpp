#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "A Dog as been created by the default constructor" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "A Dog as been created by the copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Assignement operator as been called on Dog" << std::endl;
	if (this == &other)
		return (*this);
	this->type = other.getType();
	return (*this);
}

Dog::~Dog()
{
	std::cout << "A Dog as been destroyed" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Ouaf" << std::endl;
}