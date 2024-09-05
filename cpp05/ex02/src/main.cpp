#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat bureaucrat("Fred", 5);
	PresidentialPardonForm form("test");
	bureaucrat.signForm(form);
	bureaucrat.executeForm(form);
	std::cout << std::endl;

	RobotomyRequestForm form2("test2");
	bureaucrat.signForm(form2);
	bureaucrat.executeForm(form2);
	std::cout << std::endl;

	ShrubberyCreationForm form3("test3");
	bureaucrat.signForm(form3);
	bureaucrat.executeForm(form3);
	std::cout << std::endl;

	Bureaucrat bureaucrat2("Freddy", 137);
	PresidentialPardonForm form4("test4");
	bureaucrat2.signForm(form3);
	bureaucrat2.signForm(form4);
	bureaucrat2.executeForm(form4);
	bureaucrat.signForm(form4);
	bureaucrat2.executeForm(form4);
}