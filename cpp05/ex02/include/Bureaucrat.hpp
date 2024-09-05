#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#define MAX_GRADE 1
#define MIN_GRADE 150

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		explicit Bureaucrat(int grade);
		explicit Bureaucrat(const std::string& name);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat(void);

		const std::string& getName(void) const;
		int	getGrade(void) const;

		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(AForm& form) const;
		void executeForm(AForm const & form) const;


	private:
		const std::string name;
		int	grade;

		class GradeTooHighException: public std::exception
		{
				virtual const char* what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
				virtual const char* what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif