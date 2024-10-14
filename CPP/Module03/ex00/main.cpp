#include "ClapTrap.hpp"

int main() {
    std::cout << "\033[32mConstruction...\033[0m\n";
    ClapTrap claptrap("CT-1");

    std::cout << "\033[33m\nTesting...\033[0m\n";
    claptrap.attack("Enemy");
    claptrap.takeDamage(3);
    claptrap.beRepaired(5);
    claptrap.attack("Enemy");
    claptrap.takeDamage(10);
    claptrap.beRepaired(2);

    std::cout << "\033[31m\nDestruction...\033[0m\n";

    return 0;
}
