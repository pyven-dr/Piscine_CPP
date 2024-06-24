#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());

	src->learnMateria(new Ice()); //Full MateriaSource


	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("uezrzeg"); //unknow materia;

	tmp = src->createMateria("cure");
	me->equip(tmp); //Character inventory full

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	me->use(-1, *bob); //Invalid index
	me->use(4, *bob);

	tmp = src->createMateria("ice");
	bob->equip(tmp);
	bob->unequip(0);
	delete tmp;
	bob->use(0, *me);


	delete bob;
	delete me;
	delete src;
	return 0;
}