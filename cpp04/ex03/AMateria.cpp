#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : type("Unknow")
{
}

AMateria::AMateria(std::string const & type) : type(type)
{
}

AMateria::AMateria(const AMateria& copy) : type(copy.type)
{
}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this == &other)
        return (*this);

    this->type = other.type;
    return (*this);
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "An unknow materia as been used on " << target.getName() << std::endl;
}
