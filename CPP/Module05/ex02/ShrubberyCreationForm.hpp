#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
    std::string target;

protected:
    void executeAction() const;

public:
    ShrubberyCreationForm(const std::string& target);
    ~ShrubberyCreationForm();
};

#endif
