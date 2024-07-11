#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "An Animal as been created by the default constructor" << std::endl;
	this->type = "Animal";
}

Animal::Animal(const std::string& type)
{
	std::cout << "An Animal as been created by the default constructor" << std::endl;
	this->type = type;
}

Animal::Animal(const Animal &copy)
{
	this->type = copy.getType();
	std::cout << "An animal as been created by the copy constructor" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Assignement operator as been called on Animal " << this->type << std::endl;
	if (this == &other)
		return (*this);
	this->type = other.getType();
	return (*this);
}

Animal::~Animal()
{
	std::cout << "An Animal as been destroyed" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->type);
}

void Animal::makeSound(void) const
{
	std::cout << "Animal sound" << std::endl;
}
