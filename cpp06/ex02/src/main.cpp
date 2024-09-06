#include <ctime>
#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base *generate(void);
void identify(Base* p);
void identify(const Base& p);

int main(void)
{
	A AClass;
	B BClass;
	C CClass;
	Base BaseClass;

	identify(&AClass);
	identify(&BClass);
	identify(&CClass);
	identify(&BaseClass);

	std::cout << std::endl;

	identify(AClass);
	identify(BClass);
	identify(CClass);
	identify(BaseClass);

	std::cout << std::endl;

	Base *randomClass = generate();
	identify(randomClass);
	identify(*randomClass);

	delete randomClass;
	return (0);
}

Base *generate(void)
{
	int random_number;
	std::srand(static_cast<unsigned>(std::time(0)));
	random_number = std::rand() % 3;
	switch (random_number)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		default:
			return (new C());
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(const Base& p)
{
	try
	{
		static_cast<void>(dynamic_cast<const A&>(p));
		std::cout << "A" << std::endl;
		return;
	}
	catch (const std::bad_cast& error) {}
	try
	{
		static_cast<void>(dynamic_cast<const B&>(p));
		std::cout << "B" << std::endl;
		return;
	}
	catch (const std::bad_cast& error) {}
	try
	{
		static_cast<void>(dynamic_cast<const C&>(p));
		std::cout << "C" << std::endl;
		return;
	}
	catch (const std::bad_cast& error)
	{
		std::cout << "Unknown type" << std::endl;
	}
}
