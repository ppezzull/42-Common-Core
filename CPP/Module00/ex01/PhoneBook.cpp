/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 05:41:41 by ppezzull          #+#    #+#             */
/*   Updated: 2024/08/06 05:41:44 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Contact class implementation
Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

Contact::~Contact() {}

void Contact::setDetails(const std::string &fName, const std::string &lName, const std::string &nickName,
                         const std::string &phone, const std::string &secret)
{
    firstName = fName;
    lastName = lName;
    nickname = nickName;
    phoneNumber = phone;
    darkestSecret = secret;
}

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }

void Contact::display() const
{
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

// PhoneBook class implementation
PhoneBook::PhoneBook() : len(0) {}

PhoneBook::~PhoneBook() {}

void getInput(const std::string& prompt, std::string& input) {
            clearerr(stdin);
		std::cin.clear();
    std::cout << prompt;
    std::getline(std::cin, input); // Use getline to allow spaces

    // Check if the input is empty
    if (input.empty()) {
        std::cout << "Input cannot be empty. Please try again.\n";
        getInput(prompt, input); // Recursive call
    }
}

bool isNumeric(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i])) {
            return false; // Return false if any character is not a digit
        }
    }
    return true; // All characters are digits
}

void PhoneBook::add()
{
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
    std::cin.ignore();
    getInput("Enter first name: ", firstName);
    getInput("Enter last name: ", lastName);
    getInput("Enter nickname: ", nickname);

    while (true) {
        getInput("Enter phone number: ", phoneNumber);
        if (isNumeric(phoneNumber)) {
            break; // Exit loop if phone number is valid
        } else {
            std::cout << "Phone number must contain only digits. Please try again.\n";
        }
    }

    getInput("Enter darkest secret: ", darkestSecret);
    clearerr(stdin);
    std::cin.clear();

    contacts[len].setDetails(firstName, lastName, nickname, phoneNumber, darkestSecret);
    len = (len + 1) % maxContacts;
}

void PhoneBook::search() const
{
    if (contacts[0].getFirstName().empty())
    {
        std::cout << "No contacts to search\n";
        return;
    }
    std::cout << std::setw(10) << "Index" << '|'
              << std::setw(10) << "First Name" << '|'
              << std::setw(10) << "Last Name" << '|'
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < maxContacts; ++i)
    {
        if (!contacts[i].getFirstName().empty())
        {
            std::cout << std::setw(10) << i << '|'
                      << std::setw(10) << truncate(contacts[i].getFirstName()) << '|'
                      << std::setw(10) << truncate(contacts[i].getLastName()) << '|'
                      << std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
        }
    }

    int index;
    std::cout << "Enter the index of the contact to view: ";
    std::cin >> index;

    if (index < 0 || index >= maxContacts || contacts[index].getFirstName().empty())
    {
        std::cout << "Invalid index.\n";
    }
    else
    {
        contacts[index].display();
    }
}

std::string PhoneBook::truncate(const std::string &str) const
{
    if (str.length() > 10)
    {
        return str.substr(0, 9) + '.';
    }
    return str;
}
