#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
protected:
    std::string type;

public:
    AAnimal();
    virtual ~AAnimal();
    AAnimal(const AAnimal &other);
    AAnimal &operator=(const AAnimal &other);

    virtual void makeSound() const = 0; // Pure virtual function
    std::string getType() const;

    // Virtual functions for interacting with ideas
    virtual void setIdea(int index, const std::string &idea) = 0;
    virtual std::string getIdea(int index) const = 0;
};

#endif
