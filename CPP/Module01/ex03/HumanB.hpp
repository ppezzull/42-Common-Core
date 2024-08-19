#ifndef HUMANB
#define HUMANB

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
    std::string _name;
    Weapon _weapon;
public:
    HumanB(std::string name);
    ~HumanB();

    void setWeapon(Weapon weapon);
    
    void attack() const;
};

#endif