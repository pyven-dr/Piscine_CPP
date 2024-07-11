#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	add_contact();
		void	search_contact();
		void	print_contact(int index);
		Contact	get_contact(int index);
	private:
		Contact	constact_list[8];
		int	nb_contact;
};

#endif