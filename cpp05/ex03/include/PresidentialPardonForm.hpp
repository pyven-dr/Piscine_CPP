#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		explicit PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm(void);

		void execute(Bureaucrat const & executor) const;

	private:
		const std::string target;
};

#endif
