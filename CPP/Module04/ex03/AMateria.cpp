#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    // Implementation for use, can be empty or output something
    std::cout << "Using materia on " << target.getName() << std::endl;
}
