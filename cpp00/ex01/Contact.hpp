#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	public:
		Contact();
		~Contact();
		std::string	get_fname() const;
		std::string	get_lname() const;
		std::string get_nname() const;
		std::string	get_phone_num() const;
		std::string get_secret() const;
		void		set_fname(std::string fname);
		void		set_lname(std::string lname);
		void		set_nname(std::string nname);
		void		set_phone_num(std::string phone_num);
		void		set_secret(std::string secret);

	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_num;
		std::string darkest_secret;
};

#endif
