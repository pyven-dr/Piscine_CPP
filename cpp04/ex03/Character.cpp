#include "Character.hpp"
#include <iostream>

Character::Character() : name("nameless"), inventory()
{
}

Character::Character(std::string name) : name(name), inventory()
{
}

Character::Character(const Character &copy) : name(copy.name)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy.inventory[i] != NULL)
			this->inventory[i] = copy.inventory[i]->clone();
	}
}

Character &Character::operator=(const Character &other)
{
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
		if (other.inventory[i] != NULL)
			this->inventory[i] = other.inventory[i]->clone();
		if (other.inventory[i] == NULL)
			this->inventory[i] = NULL;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
	}
}

std::string const &Character::getName() const
{
	return (this->name);
}

void Character::use(int idx, ICharacter &target)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << "Index is invalid" << std::endl;
		return ;
	}

	if (this->inventory[idx] == NULL)
		std::cout << "Inventory slot " << idx << " is empty" << std::endl;

	if (this->inventory[idx] != NULL)
		this->inventory[idx]->use(target);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return ;
		}
	}
	std::cout << "Inventory full" << std::endl;
	delete m;
}

void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << "Index is invalid" << std::endl;
		return ;
	}

	if (this->inventory[idx] == NULL)
		std::cout << "Inventory slot " << idx << " is empty" << std::endl;

	if (this->inventory[idx] != NULL)
		this->inventory[idx] = NULL;
}
