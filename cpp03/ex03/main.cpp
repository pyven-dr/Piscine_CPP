#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	DiamondTrap DiamondTrap1("DiamondTrap1");
	std::cout << std::endl;
	DiamondTrap nameless;
	std::cout << std::endl;
	DiamondTrap DiamondTrap2;
	DiamondTrap2 = DiamondTrap("DiamondTrap2");
	std::cout << std::endl;

	for (int i = 0; i <= 100; i++)
		DiamondTrap2.attack("Ennemy");

	DiamondTrap2.beRepaired(1);
	std::cout << std::endl;

	DiamondTrap1.takeDamage(9);
	DiamondTrap1.beRepaired(9);
	DiamondTrap1.takeDamage(100);
	DiamondTrap1.beRepaired(100);
	DiamondTrap1.takeDamage(100);
	DiamondTrap1.attack("Ennemy");
	std::cout << std::endl;

	nameless.attack("Ennemy");
	nameless.beRepaired(100);
	nameless.takeDamage(99);
	nameless.whoAmI();
	nameless.highFivesGuys();
	nameless.gardGate();
	std::cout << std::endl;
}