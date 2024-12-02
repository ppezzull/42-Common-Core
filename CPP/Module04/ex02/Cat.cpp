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
        AAnimal::operator=(other);
        delete brain;  // Free the existing brain memory
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea) {
    if (brain)
        brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    if (brain)
        return brain->getIdea(index);
    return "";
}
