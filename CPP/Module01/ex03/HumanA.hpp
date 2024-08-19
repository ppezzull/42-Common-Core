#ifndef HUMANA
#define HUMANA

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
    std::string _name;
    Weapon _weapon;
public:
    HumanA(std::string name, Weapon weapon);
    ~HumanA();

    void attack() const;
};

#endif