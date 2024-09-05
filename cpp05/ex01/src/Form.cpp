#include "Form.hpp"

Form::Form() : name("Unnamed form"), isSigned(false), gradeToSign(MIN_GRADE), gradeToExecute(MIN_GRADE) {}

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute) :
			name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw Form::GradeTooHighException();
	else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : name(copy.name), isSigned(copy.isSigned),
							   gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return (*this);
}

Form::~Form() {}

const std::string Form::getName() const
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

int Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	if (this->isSigned == true)
		throw Form::AlreadySignedException();
	this->isSigned = true;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::AlreadySignedException::what() const throw()
{
	return ("Form already signed");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	if (form.getIsSigned() == false)
		os << form.getName() << ", Form not signed, Grade to sign : " << form.getGradeToSign() << " , Grade to execute : " << form.getGradeToExecute() << std::endl;
	else
		os << form.getName() << ", Form signed, Grade to sign : " << form.getGradeToSign() << " , Grade to execute : " << form.getGradeToExecute() << std::endl;
	return (os);
}