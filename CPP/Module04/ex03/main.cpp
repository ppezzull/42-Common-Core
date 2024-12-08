#include "MateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
    std::cout << "\033[32mConstruction...\033[0m\n";
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    
    std::cout << "\033[33m\nTesting...\033[0m\n";
    me->use(0, *bob);
    me->use(1, *bob);
    
    me->unequip(0);

    std::cout << "\033[31m\nDestruction...\033[0m\n";
    delete bob;
    delete me;
    delete src;

    return 0;
}
