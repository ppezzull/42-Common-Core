#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    ClapTrap claptrap("CLTP");
    claptrap.attack("target1");

    ScavTrap scavtrap("SCVT");
    scavtrap.attack("target2");

    FragTrap fragtrap("FRGT");
    fragtrap.attack("target3");

    DiamondTrap diamondtrap("DMT");
    diamondtrap.attack("target4");
    diamondtrap.whoAmI();
    diamondtrap.highFivesGuys();

    return 0;
}
