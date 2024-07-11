#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat"), brain(new Brain)
{
	std::cout << "A Cat as been created by the default constructor" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy), brain(new Brain(*copy.brain))
{
	std::cout << "A Cat as been created by the copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Assignement operator as been called on Cat" << std::endl;
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	*this->brain = *other.brain;
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "A Cat as been destroyed" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Miaou" << std::endl;
}

std::string Cat::GetIdea(int index) const
{
	return (this->brain->GetIdea(index));
}

void Cat::AddIdea(const std::string &idea)
{
	this->brain->AddIdea(idea);
}