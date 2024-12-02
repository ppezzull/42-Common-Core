#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    std::cout << "\033[32mConstruction...\033[0m\n";
    const int numAAnimals = 4;
    AAnimal* AAnimals[numAAnimals];

    for (int i = 0; i < numAAnimals; i++) {
        if (i < numAAnimals / 2) {
            AAnimals[i] = new Dog();
        } else {
            AAnimals[i] = new Cat();
        }
    }

    std::cout << "\033[33m\nTesting...\033[0m\n";
    
    // Set and test ideas for Dog1
    AAnimals[0]->setIdea(0, "Chase the ball");
    std::cout << AAnimals[0]->getType() << "1's first idea: " 
              << AAnimals[0]->getIdea(0) << "\n";

    // Deep copy test from Dog1 to Dog2
    *AAnimals[1] = *AAnimals[0];
    std::cout << AAnimals[1]->getType() << "2's first idea (copied from Dog1): " 
              << AAnimals[1]->getIdea(0) << "\n";

    // Set and test ideas for Cat1
    AAnimals[2]->setIdea(0, "Sleep on the couch");
    std::cout << AAnimals[2]->getType() << "1's first idea: " 
              << AAnimals[2]->getIdea(0) << "\n";

    // Deep copy test from Cat1 to Cat2
    *AAnimals[3] = *AAnimals[2];
    std::cout << AAnimals[3]->getType() << "2's first idea (copied from Cat1): " 
              << AAnimals[3]->getIdea(0) << "\n";

    std::cout << "\033[31m\nDestruction...\033[0m\n";
    for (int i = 0; i < numAAnimals; ++i) {
        delete AAnimals[i];
    }

    return 0;
}
