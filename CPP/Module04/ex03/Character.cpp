#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : _name(name) {
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
    std::cout << "Character " << name << " created!" << std::endl;
}

Character::Character(const Character& other) {
    *this = other;
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        _name = other._name;
        for (int i = 0; i < 4; ++i) {
            if (_inventory[i])
                delete _inventory[i];
            _inventory[i] = other._inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; ++i) {
        if (_inventory[i])
            delete _inventory[i];
    }
    std::cout << "Character " << _name << " destroyed!" << std::endl;
}

std::string const & Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (!_inventory[i]) {
            _inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && _inventory[idx])
    {
        delete _inventory[idx];
        _inventory[idx] = NULL; 
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx]->use(target);
}
