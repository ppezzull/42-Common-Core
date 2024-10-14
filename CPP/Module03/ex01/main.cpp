#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "\033[32mConstruction...\033[0m\n";
    ClapTrap claptrap("CLTP");
    ScavTrap scavtrap("SCVT");

    std::cout << "\033[33m\nTesting...\033[0m\n";
    claptrap.attack("target1");
    claptrap.takeDamage(3);
    claptrap.beRepaired(2);
    scavtrap.attack("target2");
    scavtrap.guardGate();
    scavtrap.takeDamage(10);
    scavtrap.beRepaired(5);

    std::cout << "\033[31m\nDestruction...\033[0m\n";

    return 0;
}
