#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {
public:
    virtual ~Animal() = 0; // Pure virtual destructor
    virtual void makeSound() const = 0;
};

#endif
