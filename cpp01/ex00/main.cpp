#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie1 = newZombie("zombie_on_heap");
	zombie1->announce();
	randomChump("zombie_on_stack");
	delete zombie1;
	return (0);
}