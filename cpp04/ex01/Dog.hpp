#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog& other);
		~Dog();

		void	makeSound(void) const;
		void		AddIdea(const std::string& idea);
		std::string	GetIdea(int index) const;

	private:
		Brain *brain;
};

#endif