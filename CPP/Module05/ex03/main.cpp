#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        Intern intern;
        Bureaucrat boss("Boss", 1);

        AForm* shrubbery = intern.makeForm("shrubbery creation", "Garden");
        AForm* robotomy = intern.makeForm("robotomy request", "Bender");
        AForm* pardon = intern.makeForm("presidential pardon", "Arthur");
        AForm* invalid = intern.makeForm("invalid form", "Nowhere");

        if (shrubbery) {
            boss.signForm(*shrubbery);
            boss.executeForm(*shrubbery);
        }

        if (robotomy) {
            boss.signForm(*robotomy);
            boss.executeForm(*robotomy);
        }

        if (pardon) {
            boss.signForm(*pardon);
            boss.executeForm(*pardon);
        }

        delete shrubbery;
        delete robotomy;
        delete pardon;
        delete invalid;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
