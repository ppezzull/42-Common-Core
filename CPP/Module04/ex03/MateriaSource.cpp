#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i)
        _templates[i] = NULL;
    std::cout << "MateriaSource created" << std::endl;

}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        if (_templates[i])
            delete _templates[i];
    }
    std::cout << "MateriaSource deleted" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (!_templates[i]) {
            _templates[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (_templates[i] && _templates[i]->getType() == type)
            return _templates[i]->clone();
    }
    return NULL;
}
