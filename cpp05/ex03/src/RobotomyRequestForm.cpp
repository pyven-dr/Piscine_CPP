#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() :
		AForm("RobotomyRequestForm", 72, 45), target("Unnamed target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
		AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), target(copy.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	this->check_execute(executor);
	std::cout << "VrrrVrrrVrrr" << std::endl;
	std::srand(static_cast<unsigned>(std::time(0)));
	if (std::rand() % 2 == 1)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomization of " << this->target << " has failed" << std::endl;
}