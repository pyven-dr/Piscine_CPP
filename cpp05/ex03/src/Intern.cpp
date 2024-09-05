#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy) {(void)copy;}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern() {}

int	find_form_type(const std::string &form_name)
{
	const std::string form_types[3] = {SHRUB_CREATION, ROBOTOMY, PRES_PARDON};

	for (int i = 0; i < 3; i++)
		if (form_types[i] == form_name)
			return (i);
	return (-1);
}

AForm *Intern::makeForm(std::string form_name, std::string target_name)
{
	int index_form = find_form_type(form_name);

	switch (index_form)
	{
		case 0:
			std::cout << "Intern creates a Shrubbery creation form" << std::endl;
			return (new ShrubberyCreationForm(target_name));
		case 1:
			std::cout << "Intern creates a Robotomy request form" << std::endl;
			return (new RobotomyRequestForm(target_name));
		case 2:
			std::cout << "Intern creates a Presidential pardon form" << std::endl;
			return (new PresidentialPardonForm(target_name));
		default:
			std::cout << "Inter can't create a form of type : " << form_name << std::endl;
			return (NULL);
	}
}