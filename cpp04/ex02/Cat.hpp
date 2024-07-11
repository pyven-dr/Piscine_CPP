#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& other);
		~Cat();

		void	makeSound(void) const;
		void		AddIdea(const std::string& idea);
		std::string	GetIdea(int index) const;

	private:
		Brain *brain;
};

#endif