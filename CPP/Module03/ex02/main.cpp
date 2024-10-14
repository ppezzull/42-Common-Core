#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "\033[32mConstruction...\033[0m\n";
    ClapTrap claptrap("CLTP");
    ScavTrap scavtrap("SCVT");
    FragTrap fragtrap("FRGT");

    std::cout << "\033[33m\nTesting...\033[0m\n";
    claptrap.attack("target1");
    claptrap.takeDamage(3);
    claptrap.beRepaired(2);
    scavtrap.attack("target2");
    scavtrap.guardGate();
    scavtrap.takeDamage(10);
    scavtrap.beRepaired(5);
    fragtrap.attack("target3");
    fragtrap.highFivesGuys();
    fragtrap.takeDamage(50);
    fragtrap.beRepaired(10);

    std::cout << "\033[31m\nDestruction...\033[0m\n";

    return 0;
}
