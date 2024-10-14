#include "ClapTrap.hpp"


ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " created!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << "ClapTrap " << name << " attacks " << target 
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--; 
    } else {
        std::cout << "ClapTrap " << name << " has no energy or hit points!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints > 0) {
        std::cout << "ClapTrap " << name << " takes " << amount << " damage";
        if (amount >= hitPoints) {
            hitPoints = 0;
            std::cout << " and gets destroyed!" << std::endl;
        } else {
            hitPoints -= amount;
            std::cout << ", remaining hit points: " << hitPoints << std::endl;
        }
    } else {
        std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints > 0 && energyPoints > 0) {
        hitPoints += amount;
        energyPoints--; 
        std::cout << "ClapTrap " << name << " repairs itself for " << amount 
                  << " hit points, current hit points: " << hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " cannot repair itself!" << std::endl;
    }
}
