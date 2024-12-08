#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : _type(type) {
    std::cout << "AMateria of type " << type << " created!" << std::endl;
}

AMateria::~AMateria() {
    std::cout << "AMateria of type " << _type << " destroyed!" << std::endl;
}

std::string const & AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "Using materia on " << target.getName() << std::endl;
}
