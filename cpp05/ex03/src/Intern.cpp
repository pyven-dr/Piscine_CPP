#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

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

AForm *createShrubForm(std::string target_name)
{
	return (new ShrubberyCreationForm(target_name));
}

AForm *createRobForm(std::string target_name)
{
	return (new RobotomyRequestForm(target_name));
}

AForm *createPresForm(std::string target_name)
{
	return (new PresidentialPardonForm(target_name));
}

AForm *Intern::makeForm(std::string form_name, std::string target_name)
{
	int index_form = find_form_type(form_name);
	if (index_form == -1)
	{
		std::cout << "Intern can't create a form of type : " << form_name << std::endl;
		return (NULL);
	}
	AForm* (*FormCreator[3])(std::string) = {createShrubForm, createRobForm,createPresForm};
	std::cout << "Intern created " << form_name << std::endl;
	return (FormCreator[index_form](target_name));
}