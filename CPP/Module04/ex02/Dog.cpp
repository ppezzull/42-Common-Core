#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog created!" << std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destroyed!" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other) {
    brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        AAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea) {
    brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return brain->getIdea(index);
}
