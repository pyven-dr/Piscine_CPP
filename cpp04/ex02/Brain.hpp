#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain& copy);
		Brain& operator=(const Brain& other);
		~Brain();

		void		AddIdea(const std::string& idea);
		std::string	GetIdea(int index) const;

	private:
		std::string ideas[100];
		int	index_ideas;
};

#endif