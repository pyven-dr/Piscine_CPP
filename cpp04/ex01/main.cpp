#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	std::cout << std::endl << "------------------- Create array of animals----------------" << std::endl << std::endl;

	Animal *animal_array[10];

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animal_array[i] = new Cat();
		else
			animal_array[i] = new Dog();
	}

	for(int i = 0; i < 10; i++)
		animal_array[i]->makeSound();
	std::cout << std::endl;

	std::cout << std::endl << "-------------------Delete array of animals----------------" << std::endl << std::endl;

	for(int i = 0; i < 10; i++)
		delete animal_array[i];
	std::cout << std::endl;

	std::cout << std::endl << "-------------------Sound of Cat and Dog----------------" << std::endl << std::endl;

	Cat *cat = new Cat();
	Dog *dog = new Dog();
	std::cout << std::endl;

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl << std::endl;

	cat->makeSound();
	dog->makeSound();
	std::cout << std::endl;

	std::cout << std::endl << "-------------------Test ideas----------------" << std::endl << std::endl;

	cat->AddIdea("Cool idea");
	cat->AddIdea("Bad idea");
	std::cout << cat->GetIdea(0) << std::endl;
	std::cout << cat->GetIdea(1) << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << "-------------------Test deep copy of assignement operator----------------" << std::endl << std::endl;

	Cat *cat2 = new Cat();

	*cat2 = *cat;
	std::cout << cat2->GetIdea(1) << std::endl;
	std::cout << cat->GetIdea(1) << std::endl;
	cat2->AddIdea("cat2 idea");
	std::cout << cat2->GetIdea(2) << std::endl;
	std::cout << cat->GetIdea(2) << std::endl;
	std::cout << std::endl;
	delete cat2;

	std::cout << std::endl << "-------------------Test deep copy of copy constructor----------------" << std::endl << std::endl;

	Cat *cat3 = new Cat(*cat);

	std::cout << cat3->GetIdea(1) << std::endl;
	std::cout << cat->GetIdea(1) << std::endl;
	cat3->AddIdea("cat3 idea");
	std::cout << cat3->GetIdea(2) << std::endl;
	std::cout << cat->GetIdea(2) << std::endl;
	std::cout << std::endl;
	delete cat;
	delete cat3;

	std::cout << std::endl << "-------------------Test limits of ideas----------------" << std::endl << std::endl;

	for(int i = 0; i < 110; i++)
		dog->AddIdea("Some idea");
	std::cout << dog->GetIdea(99) << std::endl;
	delete dog;
	std::cout << std::endl;

	return 0;
}