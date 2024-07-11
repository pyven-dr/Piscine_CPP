#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{
	std::cout << "Harl as been created" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl as been destroyed" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << DEBUG << std::endl;
	std::cout << std::endl;
	this->info();
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << INFO << std::endl;
	std::cout << std::endl;
	this->warning();
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << WARNING << std::endl;
	std::cout << std::endl;
	this->error();
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << ERROR << std::endl;
	std::cout << std::endl;
}

int	get_index(std::string level)
{
	std::string level_list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == level_list[i])
			return (i);
	}
	return (-1);
}

void Harl::complain(std::string level)
{
	int	index = get_index(level);

	switch (index)
	{
		case 0:
			this->debug();
			break;
		case 1:
			this->info();
			break;
		case 2:
			this->warning();
			break;
		case 3:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
