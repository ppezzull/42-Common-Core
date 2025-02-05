#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrubbery("Garden");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Arthur");

        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);

        bob.signForm(robotomy);
        bob.executeForm(robotomy);

        bob.signForm(pardon);
        bob.executeForm(pardon);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
