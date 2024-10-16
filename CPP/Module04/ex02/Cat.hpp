#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
private:
    Brain* brain;
public:
    Cat();
    ~Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);

    void makeSound() const; // Implementation of the pure virtual function
    void setIdea(int index, const std::string &idea);
    std::string getIdea(int index) const;
};

#endif
