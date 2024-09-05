#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		explicit ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm(void);

		void execute(Bureaucrat const & executor) const;

	private:
		const std::string target;
};

#endif