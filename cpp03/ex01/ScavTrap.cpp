#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "A nameless ScavTrap as been created by the default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "A ScavTrap named " << this->name << " as been created by the default constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "A ScavTrap named " << this->name << " as been created by the copy constructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "Assignment operator as been called on ScavTrap " << this->name << std::endl;
	if (this == &other)
		return (*this);
	this->name = other.name;
	this->HitPoints = other.HitPoints;
	this->EnergyPoints = other.EnergyPoints;
	this->AttackDamage = other.AttackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "A ScavTrap named " << this->name << " as been destroyed" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->EnergyPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " can't attack because he's out of energy" << std::endl;
		return ;
	}
	if (this->HitPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " can't attack because he's dead" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target \
				<< ", causing " << this->AttackDamage << " points of damage !" << std::endl;
	this->EnergyPoints--;
}

void ScavTrap::gardGate(void)
{
	std::cout << "ScavTrap " << this->name << " enter in Gate keeper mode" << std::endl;
}