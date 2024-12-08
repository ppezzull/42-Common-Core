#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat created!" << std::endl;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destroyed!" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other) {
    brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        AAnimal::operator=(other); // Call the base class assignment operator
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
