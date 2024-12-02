#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat john("John", 50);
        Bureaucrat jane("Jane", 1);

        std::cout << john << std::endl;
        std::cout << jane << std::endl;

        john.incrementGrade();
        jane.incrementGrade();

        std::cout << john << std::endl;
        std::cout << jane << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat invalidHigh("High", 0);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat invalidLow("Low", 151);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
