#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"

#define PRES_PARDON "PresidentialPardonForm"
#define ROBOTOMY "RobotomyRequestForm"
#define SHRUB_CREATION "ShrubberyCreationForm"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern& copy);
		Intern& operator=(const Intern& other);
		~Intern(void);

		static AForm* makeForm(std::string form_name, std::string target_name);
};

#endif