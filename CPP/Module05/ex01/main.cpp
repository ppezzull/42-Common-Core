#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat john("John", 50);
        Form contract("Contract", 30, 40);

        std::cout << john << std::endl;
        std::cout << contract << std::endl;

        john.signForm(contract);

        Bureaucrat boss("Boss", 20);
        boss.signForm(contract);

        std::cout << contract << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
