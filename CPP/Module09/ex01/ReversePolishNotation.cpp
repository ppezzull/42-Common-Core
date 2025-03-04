#include "ReversePolishNotation.hpp"
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

ReversePolishNotation::ReversePolishNotation() {}

ReversePolishNotation::~ReversePolishNotation() {}

double ReversePolishNotation::evaluate(const std::string &expression) const {
    std::stack<double> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                throw std::runtime_error("Error: insufficient values in expression.");
            }
            double b = stack.top(); 
            stack.pop();
            double a = stack.top(); 
            stack.pop();
            double result;
            if (token == "+")
                result = a + b;
            else if (token == "-")
                result = a - b;
            else if (token == "*")
                result = a * b;
            else if (token == "/") {
                if (b == 0)
                    throw std::runtime_error("Error: division by zero.");
                result = a / b;
            }
            stack.push(result);
        } else {
            double num = atof(token.c_str());
            stack.push(num);
        }
    }
    if (stack.size() != 1) {
        throw std::runtime_error("Error: invalid expression.");
    }
    return stack.top();
}
