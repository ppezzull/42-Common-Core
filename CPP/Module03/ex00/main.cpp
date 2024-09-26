#include "ClapTrap.hpp"

int main() {
    ClapTrap claptrap("CT-1");

    claptrap.attack("Enemy");
    claptrap.takeDamage(3);
    claptrap.beRepaired(5);
    claptrap.attack("Enemy");
    claptrap.takeDamage(10);
    claptrap.beRepaired(2);

    return 0;
}
