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
	std::cout << DEBUG << std::endl;
}

void Harl::info(void)
{
	std::cout << INFO << std::endl;
}

void Harl::warning(void)
{
	std::cout << WARNING << std::endl;
}

void Harl::error(void)
{
	std::cout << ERROR << std::endl;
}

void Harl::complain(std::string level)
{
	std::string level_list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcs_pointer[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level == level_list[i])
		{
			(this->*funcs_pointer[i])();
			return ;
		}
	}
}
