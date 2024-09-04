#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"


class AForm
{
	public:
		AForm(void);
		AForm(const std::string& name, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& other);
		~AForm(void);

		const std::string getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;

		void beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException: public std::exception
		{
				virtual const char* what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
				virtual const char* what(void) const throw();
		};
		class AlreadySignedException: public std::exception
		{
				virtual const char* what(void) const throw();
		};

	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
