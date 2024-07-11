#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << std::endl;

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl << std::endl;

	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	std::cout << std::endl;

	delete animal;
	delete dog;
	delete cat;
	std::cout << std::endl;

	const WrongAnimal* wrong_animal = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();
	std::cout << std::endl;

	std::cout << wrong_cat->getType() << " " << std::endl << std::endl;

	wrong_cat->makeSound();
	wrong_animal->makeSound();
	std::cout << std::endl;

	delete wrong_animal;
	delete wrong_cat;

	return 0;
}