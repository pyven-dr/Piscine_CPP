#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::get_fname() const
{
	return (this->first_name);
}

std::string Contact::get_lname() const
{
	return (this->last_name);
}

std::string Contact::get_nname() const
{
	return (this->nickname);
}

std::string Contact::get_phone_num() const
{
	return (this->phone_num);
}

std::string Contact::get_secret() const
{
	return (this->darkest_secret);
}

void Contact::set_fname(std::string fname)
{
	this->first_name = fname;
}

void Contact::set_lname(std::string lname)
{
	this->last_name = lname;
}

void Contact::set_nname(std::string nname)
{
	this->nickname = nname;
}

void Contact::set_phone_num(std::string phone_num)
{
	this->phone_num = phone_num;
}

void Contact::set_secret(std::string secret)
{
	this->darkest_secret = secret;
}