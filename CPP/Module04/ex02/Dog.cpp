#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
    brain = new Brain();
    std::cout << "Dog constructed." << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal() {
    brain = new Brain(*other.brain);
    std::cout << "Dog copied." << std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructed." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment." << std::endl;
    if (this != &other) {
        delete brain;  // Avoid memory leak
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}
