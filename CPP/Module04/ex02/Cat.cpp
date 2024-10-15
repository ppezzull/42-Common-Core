#include "Cat.hpp"
#include <iostream>

// Constructor
Cat::Cat() : AAnimal() {
    this->brain = new Brain();
    std::cout << "Cat created!" << std::endl;
}

// Copy Constructor
Cat::Cat(const Cat& other) : AAnimal(other) {
    this->brain = new Brain(*other.brain);
}

// Assignment Operator
Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        AAnimal::operator=(other); // Call the base class assignment operator
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

// Destructor
Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destroyed!" << std::endl;
}

// Make Sound
void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
