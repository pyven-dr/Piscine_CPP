#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern intern;
	AForm* form;
	Bureaucrat bureaucrat("Freddy", 1);

	form = intern.makeForm(PRES_PARDON, "Fred");
	std::cout << *form << std::endl;
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	delete form;
	std::cout << std::endl;


	form = intern.makeForm("random form", "Fred");
}