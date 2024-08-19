#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon("no weapon") {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon weapon) {
    _weapon = weapon;
}

void HumanB::attack() const {
    std::cout << _name << " attacked with " << _weapon.getType() << std::endl;
}
