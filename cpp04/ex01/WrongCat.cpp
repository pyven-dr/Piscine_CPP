#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "A WrongCat as been created by the default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "A WrongCat as been created by the copy constructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "Assignement operator as been called on WrongCat" << std::endl;
	if (this == &other)
		return (*this);
	this->type = other.getType();
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "A WrongCat as been destroyed" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Miaou" << std::endl;
}