#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat bureaucrat("Fred", 20);

	Form form("Form1", 10, 20);
	Form form2("Form2", 21, 20);

	try
	{
		Form invalid_form("invalid_form", 200, 200);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try 
	{
		bureaucrat.signForm(form);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << form << std::endl;
	std::cout << std::endl;

	try
	{
		bureaucrat.signForm(form2);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << form2 << std::endl;
	std::cout << std::endl;
	
	try
	{
		bureaucrat.signForm(form2);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << form2 << std::endl;
}