#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() : memory()
{
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < 4; i++)
		this->memory[i] = copy.memory[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (this->memory[i] != NULL)
			delete this->memory[i];
		if (other.memory[i] != NULL)
			this->memory[i] = other.memory[i]->clone();
		else
			this->memory[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->memory[i] != NULL)
			delete this->memory[i];
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->memory[i] == NULL)
		{
			this->memory[i] = materia;
			return ;
		}
	}
	delete materia;
	std::cout << "Memory full" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->memory[i] != NULL && this->memory[i]->getType() == type)
			return (this->memory[i]->clone());
	}
	std::cout << "Unknow materia" << std::endl;
	return (NULL);
}

