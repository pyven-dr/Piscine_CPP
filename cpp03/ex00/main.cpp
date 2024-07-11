#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap ClapTrap1("ClapTrap1");
	ClapTrap nameless;
	ClapTrap Claptrap2;
	Claptrap2 = ClapTrap("ClapTrap2");
	std::cout << std::endl;

	for (int i = 0; i <= 10; i++)
		Claptrap2.attack("Ennemy");

	Claptrap2.beRepaired(1);
	std::cout << std::endl;

	ClapTrap1.takeDamage(9);
	ClapTrap1.beRepaired(9);
	ClapTrap1.takeDamage(20);
	ClapTrap1.beRepaired(20);
	ClapTrap1.takeDamage(20);
	ClapTrap1.attack("Ennemy");
	std::cout << std::endl;

	nameless.attack("Ennemy");
	nameless.beRepaired(100);
	nameless.takeDamage(99);
	std::cout << std::endl;
}