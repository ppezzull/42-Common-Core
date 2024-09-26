#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
    std::cout << "Brain constructed." << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = "No idea";  // Initialize ideas
    }
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copied." << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
}

Brain::~Brain() {
    std::cout << "Brain destructed." << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain assignment." << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return ideas[index];
    }
    return "";
}
