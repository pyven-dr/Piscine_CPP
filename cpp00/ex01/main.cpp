#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook phoneBook;
	std::string input_line;

	while (std::getline(std::cin, input_line))
	{
		if (input_line == "EXIT")
			break;
		else if (input_line == "ADD")
			phoneBook.add_contact();
		else if (input_line == "SEARCH")
			phoneBook.search_contact();
		else if (input_line != "EXIT")
			std::cout << "Bad input please use ADD, SEARCH or EXIT" << std::endl;
	}
}