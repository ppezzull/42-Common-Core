#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name)
    : FragTrap(name), ScavTrap(name + "_clap_name"), name(name) {
    FragTrap::hitPoints = 100;
    ScavTrap::energyPoints = 50;
    FragTrap::attackDamage = 30;
    std::cout << "DiamondTrap " << this->name << " constructed!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << name << " destroyed!" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target); 
}

void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << name 
              << " and my ClapTrap name is " << ScavTrap::name << std::endl;
}
