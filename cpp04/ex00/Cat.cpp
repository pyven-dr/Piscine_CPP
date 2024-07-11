#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	std::cout << "A Cat as been created by the default constructor" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "A Cat as been created by the copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Assignement operator as been called on Cat" << std::endl;
	if (this == &other)
		return (*this);
	this->type = other.getType();
	return (*this);
}

Cat::~Cat()
{
	std::cout << "A Cat as been destroyed" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Miaou" << std::endl;
}