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

#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

// Contact class implementation
Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

Contact::~Contact() {}

void Contact::setDetails(const std::string& fName, const std::string& lName, const std::string& nickName,
                         const std::string& phone, const std::string& secret) {
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

void Contact::display() const {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

// PhoneBook class implementation
PhoneBook::PhoneBook() : index(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::add() {
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cout << "Enter first name: ";
    std::cin.ignore();
    std::getline(std::cin, firstName);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);

    if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
        std::cout << "All fields must be filled in.\n";
        return;
    }

    contacts[index].setDetails(firstName, lastName, nickname, phoneNumber, darkestSecret);
    index = (index + 1) % maxContacts;
}

void PhoneBook::search() const {
    std::cout << std::setw(10) << "Index" << '|'
              << std::setw(10) << "First Name" << '|'
              << std::setw(10) << "Last Name" << '|'
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < maxContacts; ++i) {
        if (!contacts[i].getFirstName().empty()) {
            std::cout << std::setw(10) << i << '|'
                      << std::setw(10) << truncate(contacts[i].getFirstName()) << '|'
                      << std::setw(10) << truncate(contacts[i].getLastName()) << '|'
                      << std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
        }
    }

    int index;
    std::cout << "Enter the index of the contact to view: ";
    std::cin >> index;

    if (index < 0 || index >= maxContacts || contacts[index].getFirstName().empty()) {
        std::cout << "Invalid index.\n";
    } else {
        contacts[index].display();
    }
}

std::string PhoneBook::truncate(const std::string &str) const {
    if (str.length() > 10) {
        return str.substr(0, 9) + '.';
    }
    return str;
}
