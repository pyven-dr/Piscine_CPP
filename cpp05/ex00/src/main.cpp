#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat bureaucrat("Fred", 20);
	std::cout << bureaucrat << std::endl;
	try
	{
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
	std::cout << std::endl;

	Bureaucrat bureaucrat2("Freddy", MIN_GRADE);
	std::cout << bureaucrat2 << std::endl;
	try
	{
		bureaucrat2.decrementGrade();
		std::cout << bureaucrat2 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
		std::cout << bureaucrat2 << std::endl;
	}
	std::cout << std::endl;

	Bureaucrat bureaucrat3("Fredo", MAX_GRADE);
	std::cout << bureaucrat3 << std::endl;
	try
	{
		bureaucrat3.incrementGrade();
		std::cout << bureaucrat3 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
		std::cout << bureaucrat3 << std::endl;
	}
	std::cout << std::endl;

	Bureaucrat bureaucrat4(bureaucrat);
	std::cout << bureaucrat4 << std::endl;
	bureaucrat3 = bureaucrat;
	std::cout << bureaucrat3 << std::endl;
}