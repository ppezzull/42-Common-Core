#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* forms[3] = {new ShrubberyCreationForm(target),
                       new RobotomyRequestForm(target),
                       new PresidentialPardonForm(target)};

    for (int i = 0; i < 3; ++i) {
        if (formName == formTypes[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i];
        }
        delete forms[i];
    }

    std::cout << "Intern couldn't find the form: " << formName << std::endl;
    return NULL; 
}
