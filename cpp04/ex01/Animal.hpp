#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include "Brain.hpp"

class Animal
{
	public:
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& copy);
		Animal& operator=(const Animal& other);
		virtual ~Animal();

		virtual void	makeSound(void) const ;
		std::string		getType(void) const;

	protected:
		std::string type;
};

#endif