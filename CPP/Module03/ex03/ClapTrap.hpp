#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
protected:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    ClapTrap(const std::string& name);
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    // Getters
    std::string getName() const { return name; }
    unsigned int getHitPoints() const { return hitPoints; }
    unsigned int getEnergyPoints() const { return energyPoints; }
    unsigned int getAttackDamage() const { return attackDamage; }
};

#endif
