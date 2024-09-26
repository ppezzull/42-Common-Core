#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    const int numAnimals = 10;
    AAnimal* animals[numAnimals];

    // Create an array of animals (5 Dogs and 5 Cats)
    for (int i = 0; i < numAnimals; ++i) {
        if (i < numAnimals / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    // Make sounds
    for (int i = 0; i < numAnimals; ++i) {
        animals[i]->makeSound();
    }

    // Clean up
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i]; // Should call the appropriate destructors
    }

    return 0;
}
