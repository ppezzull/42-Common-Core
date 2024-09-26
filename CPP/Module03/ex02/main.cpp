#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    FragTrap fragtrap("FRGT");
    fragtrap.attack("target3");
    fragtrap.highFivesGuys();
    fragtrap.takeDamage(50);
    fragtrap.beRepaired(10);

    return 0;
}
