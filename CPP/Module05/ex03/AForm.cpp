#include "AForm.hpp"
#include "Bureaucrat.hpp"  // Include full definition of Bureaucrat

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign)  // This now works because Bureaucrat is included
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)  // This now works
        throw GradeTooLowException();
    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw() { return "Grade is too high!"; }
const char* AForm::GradeTooLowException::what() const throw() { return "Grade is too low!"; }
const char* AForm::FormNotSignedException::what() const throw() { return "Form is not signed!"; }
