#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("nameless") ,HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "A nameless ClapTrap as been created by the default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "A ClapTrap named " << this->name << " as been created by the default constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : name(copy.name), HitPoints(copy.HitPoints), \
									EnergyPoints(copy.EnergyPoints), AttackDamage(copy.AttackDamage)
{
	std::cout << "A ClapTrap named " << this->name << " as been created by the copy constructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Assignment operator as been called on " << this->name << std::endl;
	if (this == &other)
		return (*this);
	this->name = other.name;
	this->HitPoints = other.HitPoints;
	this->EnergyPoints = other.EnergyPoints;
	this->AttackDamage = other.AttackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "A ClapTrap named " << this->name << " as been destroyed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->EnergyPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " can't attack because he's out of energy" << std::endl;
		return ;
	}
	if (this->HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " can't attack because he's dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target \
				<< ", causing " << this->AttackDamage << " points of damage !" << std::endl;
	this->EnergyPoints--;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EnergyPoints == 0) {
		std::cout << "ClapTrap " << this->name << " can't be repair because he's out of energy"
				  << std::endl;
		return;
	}
	if (this->HitPoints == 0) {
		std::cout << "ClapTrap " << this->name << " can't be repair because he's dead"
				  << std::endl;
		return;
	}
	this->HitPoints += amount;
	this->EnergyPoints--;
	std::cout << "ClapTrap " << this->name << " is repaired by " << amount
			  << " of point leading his new health to " << this->HitPoints << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is already dead so he can't take damage" << std::endl;
		return ;
	}
	if (this->HitPoints <= amount)
	{
		this->HitPoints = 0;
		std::cout << "ClapTrap " << this->name << " takes " << amount \
				<< " points of damage and died " << std::endl;
		return ;
	}
	this->HitPoints -= amount;
	std::cout << "ClapTrap " << this->name << " takes " << amount \
				<< " points of damage leading his new health to " << this->HitPoints << std::endl;
}
