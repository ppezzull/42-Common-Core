#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(void)
{
    Zombie* heapZombie;
    heapZombie = newZombie("Foo");
    heapZombie->announce();

    randomChump("Mi cugg");

    delete heapZombie;

    return 0;
}
