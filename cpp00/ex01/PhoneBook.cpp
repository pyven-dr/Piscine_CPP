#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook()
{
	std::cout << "Welcome to phonebook" << std::endl;
	this->nb_contact = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "You're leaving phonebook, all contacts will disappear. Bye" << std::endl;
}

Contact PhoneBook::get_contact(int index)
{
	return (this->constact_list[index]);
}

void PhoneBook::add_contact()
{
	std::string temp_str;
	std::cout << "Please enter following informations, you can't leave any empty field" << std::endl;
	while (temp_str.empty() == true && std::cin.eof() == false)
	{
		std::cout << "Enter the first name of the contact" << std::endl;
		std::getline(std::cin, temp_str);
	}
	this->constact_list[this->nb_contact % 8].set_fname(temp_str);
	temp_str.clear();
	while (temp_str.empty() == true && std::cin.eof() == false)
	{
		std::cout << "Enter the last name of the contact" << std::endl;
		std::getline(std::cin, temp_str);
	}
	this->constact_list[this->nb_contact % 8].set_lname(temp_str);
	temp_str.clear();
	while (temp_str.empty() == true && std::cin.eof() == false)
	{
		std::cout << "Enter the nickname of the contact" << std::endl;
		std::getline(std::cin, temp_str);
	}
	this->constact_list[this->nb_contact % 8].set_nname(temp_str);
	temp_str.clear();
	while (temp_str.empty() == true && std::cin.eof() == false)
	{
		std::cout << "Enter the phone number of the contact" << std::endl;
		std::getline(std::cin, temp_str);
	}
	this->constact_list[this->nb_contact % 8].set_phone_num(temp_str);
	temp_str.clear();
	while (temp_str.empty() == true && std::cin.eof() == false)
	{
		std::cout << "Enter the darkest secret of the contact" << std::endl;
		std::getline(std::cin, temp_str);
	}
	this->constact_list[this->nb_contact % 8].set_secret(temp_str);
	temp_str.clear();
	this->nb_contact++;
	std::cout << "Contact successfully added" << std::endl;
}

std::string resize(std::string str)
{
	if (str.size() > 10)
	{
		str.resize(10);
		str[9] = '.';
	}
	return (str);
}

void display_contact_list(Contact contact_list[8])
{
	int i = 0;
	std::string temp_str;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	while (i < 8 && contact_list[i].get_fname().empty() == false)
	{
		std::cout << "|" << std::setw(10) << i;
		temp_str = resize(contact_list[i].get_fname());
		std::cout << "|" << std::setw(10) << temp_str;
		temp_str = resize(contact_list[i].get_lname());
		std::cout << "|" << std::setw(10) << temp_str;
		temp_str = resize(contact_list[i].get_nname());
		std::cout << "|" << std::setw(10) << temp_str << "|" << std::endl;
		i++;
	}
}

void PhoneBook::search_contact()
{
	int index;
	std::string line;
	if (this->nb_contact > 0)
	{
		display_contact_list(this->constact_list);
		std::cout << "Enter the index of the contact" << std::endl;
		while (std::getline(std::cin, line))
		{
			index = std::atoi(line.c_str());
			if (line[0] >= '0' && line[0] <= '7' && line.size() == 1)
				break ;
			std::cout << "Not a valid input" << std::endl;
			std::cout << "Enter the index of the contact" << std::endl;
		}
		if (std::cin.eof() == false)
			this->print_contact(index);
	}
}

void PhoneBook::print_contact(int index)
{
	Contact contact = this->get_contact(index);
	if (contact.get_fname().empty())
	{
		std::cout << "This contact does not exist" << std::endl;
		return ;
	}
	std::cout << "First name: " << contact.get_fname() << std::endl;
	std::cout << "Last name: " << contact.get_lname() << std::endl;
	std::cout << "Nickname: " << contact.get_nname() << std::endl;
	std::cout << "Phone number: " << contact.get_phone_num() << std::endl;
	std::cout << "Darkest secret: " << contact.get_secret() << std::endl;
}
