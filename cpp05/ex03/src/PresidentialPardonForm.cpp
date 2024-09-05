#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
		AForm("PresidentialPardonForm", 25, 5), target("Unnamed target") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
		AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), target(copy.target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	this->check_execute(executor);
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}