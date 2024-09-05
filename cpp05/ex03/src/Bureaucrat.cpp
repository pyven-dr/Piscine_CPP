#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Unnamed"), grade(MIN_GRADE) {}

Bureaucrat::Bureaucrat(const std::string& name) : name(name), grade(MIN_GRADE) {}

Bureaucrat::Bureaucrat(int grade) : name("Unnamed"), grade(grade)
{
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

const std::string &Bureaucrat::getName() const
{
	return (this->name);
}

void Bureaucrat::incrementGrade()
{
	if (this->grade == MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->grade == MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}