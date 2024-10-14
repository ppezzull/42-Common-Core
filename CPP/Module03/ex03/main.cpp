#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    std::cout << "\033[32mConstruction...\033[0m\n";
    ClapTrap claptrap("CLTP");
    ScavTrap scavtrap("SCVT");
    FragTrap fragtrap("FRGT");
    DiamondTrap diamondtrap("DMT");
    
    std::cout << "\033[33m\nTesting...\033[0m\n";
    claptrap.attack("target1");
    scavtrap.attack("target2");
    fragtrap.attack("target3");
    diamondtrap.attack("target4");
    diamondtrap.whoAmI();
    diamondtrap.highFivesGuys();

    std::cout << "\033[31m\nDestruction...\033[0m\n";

    return 0;
}
