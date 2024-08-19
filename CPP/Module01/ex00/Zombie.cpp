#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie() {
    std::cout << _name << " has been destroyed.\n";
}


void Zombie::announce( void ) const {
    if (_name == "Foo")
        std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
    else
        std::cout << "<" << _name << ">" << ": BraiiiiiiinnnzzzZ...\n";
}