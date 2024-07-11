#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	std::cout << "An WrongAnimal as been created by the default constructor" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const std::string& type)
{
	std::cout << "An WrongAnimal as been created by the default constructor" << std::endl;
	this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	this->type = copy.getType();
	std::cout << "An WrongAnimal as been created by the copy constructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "Assignement operator as been called on " << this->type << std::endl;
	if (this == &other)
		return (*this);
	this->type = other.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "An WrongAnimal as been destroyed" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal sound" << std::endl;
}