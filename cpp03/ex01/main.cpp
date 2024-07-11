#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	ScavTrap ScavTrap1("ScavTrap1");
	ScavTrap nameless;
	ScavTrap ScavTrap2;
	ScavTrap2 = ScavTrap("ScavTrap2");
	std::cout << std::endl;

	for (int i = 0; i <= 50; i++)
		ScavTrap2.attack("Ennemy");

	ScavTrap2.beRepaired(1);
	std::cout << std::endl;

	ScavTrap1.takeDamage(9);
	ScavTrap1.beRepaired(9);
	ScavTrap1.takeDamage(100);
	ScavTrap1.beRepaired(100);
	ScavTrap1.takeDamage(100);
	ScavTrap1.attack("Ennemy");
	std::cout << std::endl;

	nameless.attack("Ennemy");
	nameless.beRepaired(100);
	nameless.takeDamage(99);
	nameless.gardGate();
	std::cout << std::endl;
}