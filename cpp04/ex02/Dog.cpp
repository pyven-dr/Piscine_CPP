#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog"), brain(new Brain)
{
	std::cout << "A Dog as been created by the default constructor" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy), brain(new Brain(*copy.brain))
{
	std::cout << "A Dog as been created by the copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Assignement operator as been called on Dog" << std::endl;
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	*this->brain = *other.brain;
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "A Dog as been destroyed" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Miaou" << std::endl;
}

std::string Dog::GetIdea(int index) const
{
	return (this->brain->GetIdea(index));
}

void Dog::AddIdea(const std::string &idea)
{
	this->brain->AddIdea(idea);
}