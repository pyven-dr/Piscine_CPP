#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	FragTrap FragTrap1("FragTrap1");
	FragTrap nameless;
	FragTrap FragTrap2;
	FragTrap2 = FragTrap("FragTrap2");
	std::cout << std::endl;

	for (int i = 0; i <= 100; i++)
		FragTrap2.attack("Ennemy");

	FragTrap2.beRepaired(1);
	std::cout << std::endl;

	FragTrap1.takeDamage(9);
	FragTrap1.beRepaired(9);
	FragTrap1.takeDamage(100);
	FragTrap1.beRepaired(100);
	FragTrap1.takeDamage(100);
	FragTrap1.attack("Ennemy");
	std::cout << std::endl;

	nameless.attack("Ennemy");
	nameless.beRepaired(100);
	nameless.takeDamage(99);
	nameless.highFivesGuys();
	std::cout << std::endl;
}