#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap claptrap("CLTP");
    claptrap.attack("target1");
    claptrap.takeDamage(3);
    claptrap.beRepaired(2);

    ScavTrap scavtrap("SCVT");
    scavtrap.attack("target2");
    scavtrap.guardGate();
    scavtrap.takeDamage(10);
    scavtrap.beRepaired(5);

    return 0;
}
