#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	int	nb_zombies = 10;
	Zombie* horde = zombieHorde(nb_zombies, "zombie");

	for (int i = 0; i < nb_zombies; i++)
	{
		std::cout << "zombie " << i << ": ";
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}