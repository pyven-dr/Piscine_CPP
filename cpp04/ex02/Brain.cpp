#include "Brain.hpp"
#include <iostream>

Brain::Brain() : index_ideas(0)
{
	std::cout << "A Brain as been created by the default constructor" << std::endl;
}

Brain::Brain(const Brain &copy) : index_ideas(copy.index_ideas)
{
	std::cout << "A Brain as been created by the copy constructor" << std::endl;
	for (int i = 0; i < 100 ; i++)
		this->ideas[i] = copy.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Assignement operator called on brain" << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i < 100 ; i++)
		this->ideas[i] = other.ideas[i];
	this->index_ideas = other.index_ideas;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "A Brain as been destroyed" << std::endl;
}

std::string Brain::GetIdea(int index) const
{
	if (index >= this->index_ideas)
		return ("Index out of range");
	return (this->ideas[index]);
}

void Brain::AddIdea(const std::string &idea)
{
	if (this->index_ideas >= 100)
	{
		std::cout << "Idea array is full" << std::endl;
		return ;
	}
	std::cout << "An idea as been added at index " << this->index_ideas << std::endl;
	this->ideas[this->index_ideas] = idea;
	this->index_ideas++;
}