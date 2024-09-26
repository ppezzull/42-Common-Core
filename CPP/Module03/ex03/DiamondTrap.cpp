#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name)
    : FragTrap(name), ScavTrap(name + "_clap_name"), name(name) {
    FragTrap::hitPoints = 100; // Explicitly set hitPoints from FragTrap
    ScavTrap::energyPoints = 50; // Explicitly set energyPoints from ScavTrap
    FragTrap::attackDamage = 30; // Explicitly set attackDamage from FragTrap
    std::cout << "DiamondTrap " << this->name << " constructed!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << name << " destroyed!" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);  // Call ScavTrap's attack
}

void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << name 
              << " and my ClapTrap name is " << ScavTrap::name << std::endl; // Use ScavTrap's name
}
