#ifndef AANIMAL_HPP
#define AANIMAL_HPP

class AAnimal {
public:
    virtual ~AAnimal() = 0; // Pure virtual destructor
    virtual void makeSound() const = 0; // Pure virtual function
};

#endif
