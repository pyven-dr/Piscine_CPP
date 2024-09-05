#include "AForm.hpp"

AForm::AForm() : name("Unnamed AForm"), isSigned(false), gradeToSign(MIN_GRADE), gradeToExecute(MIN_GRADE) {}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute) :
			name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : name(copy.name), isSigned(copy.isSigned),
							   gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return (*this);
}

AForm::~AForm() {}

const std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

int AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	if (this->isSigned == true)
		throw AForm::AlreadySignedException();
	this->isSigned = true;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return ("Form already signed");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("Form not signed");
}

void AForm::check_execute(const Bureaucrat &bureaucrat) const
{
	if (this->getIsSigned() == false)
		throw AForm::NotSignedException();
	if (bureaucrat.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
	if (AForm.getIsSigned() == false)
		os << AForm.getName() << ", Form not signed, Grade to sign : " << AForm.getGradeToSign() << " , Grade to execute : " << AForm.getGradeToExecute() << std::endl;
	else
		os << AForm.getName() << ", Form signed, Grade to sign : " << AForm.getGradeToSign() << " , Grade to execute : " << AForm.getGradeToExecute() << std::endl;
	return (os);
}