#include "ClapTrap.hpp"

// Constructor
ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " created!" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

// Attack function
void ClapTrap::attack(const std::string& target) {
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << "ClapTrap " << name << " attacks " << target 
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--; // Reduce energy points by 1
    } else {
        std::cout << "ClapTrap " << name << " has no energy or hit points!" << std::endl;
    }
}

// Take damage function
void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints > 0) {
        hitPoints -= amount;
        if (hitPoints == 0) {
            std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
        } else {
            std::cout << "ClapTrap " << name << " takes " << amount 
                      << " damage, remaining hit points: " << hitPoints << std::endl;
        }
    } else {
        std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
    }
}

// Repair function
void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints > 0 && energyPoints > 0) {
        hitPoints += amount;
        energyPoints--; // Reduce energy points by 1
        std::cout << "ClapTrap " << name << " repairs itself for " << amount 
                  << " hit points, current hit points: " << hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " cannot repair itself!" << std::endl;
    }
}
