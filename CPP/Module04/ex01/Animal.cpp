#include "Animal.hpp"

Animal::Animal() : brain(new Brain()) {
    std::cout << "Animal created!" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type), brain(new Brain(*other.brain)) {}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type = other.type;
        *brain = *other.brain;
    }
    return *this;
}

Animal::~Animal() {
    delete brain;
    std::cout << "Animal destroyed!" << std::endl;
}

void Animal::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Animal::getIdea(int index) const {
    return brain->getIdea(index);
}

std::string Animal::getType() const {
    return type;
}
