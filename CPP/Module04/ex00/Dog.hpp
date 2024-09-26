#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();
    virtual ~Dog();
    void makeSound() const; // Override to specify dog sound
};

#endif
