#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    std::cout << "\033[32mConstruction...\033[0m\n";
    const int numAnimals = 4;
    Animal* animals[numAnimals];

    for (int i = 0; i < numAnimals; ++i) {
        if (i < numAnimals / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    std::cout << "\033[33m\nTesting...\033[0m\n";
    
    animals[0]->setIdea(0, "Chase the ball");
    std::cout   << animals[0]->getType() << "1's first idea: " 
                << animals[0]->getIdea(0) << "\n";

    *animals[1] = *animals[0];
    std::cout   << animals[1]->getType() << "2's first idea (copied from Dog1): " 
                << animals[1]->getIdea(0) << "\n";

    animals[2]->setIdea(0, "Sleep on the couch");
    std::cout   << animals[2]->getType() << "1's first idea: " 
                << animals[2]->getIdea(0) << "\n";

    *animals[3] = *animals[2];
    std::cout   << animals[3]->getType() << "2's first idea (copied from Cat1): " 
                << animals[3]->getIdea(0) << "\n";

    std::cout   << "\033[31m\nDestruction...\033[0m\n";
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    return 0;
}

