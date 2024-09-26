#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
    brain = new Brain();
    std::cout << "Cat constructed." << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal() {
    brain = new Brain(*other.brain);
    std::cout << "Cat copied." << std::endl;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructed." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment." << std::endl;
    if (this != &other) {
        delete brain;  // Avoid memory leak
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
