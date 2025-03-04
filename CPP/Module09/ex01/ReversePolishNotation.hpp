#ifndef REVERSEPOLISHNOTATION_HPP
#define REVERSEPOLISHNOTATION_HPP

#include <string>

class ReversePolishNotation {
public:
    ReversePolishNotation();
    ~ReversePolishNotation();

    double evaluate(const std::string &expression) const;
};

#endif
