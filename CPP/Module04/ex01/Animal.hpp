#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal {
protected:
    std::string type;
    Brain* brain;

public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    virtual void makeSound() const = 0;

    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
    std::string getType() const;
};

#endif
