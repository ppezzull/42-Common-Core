/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 04:39:33 by ppezzull          #+#    #+#             */
/*   Updated: 2024/08/06 04:39:35 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <cstdio>
#include <iomanip>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    ~Contact();

    void setDetails(const std::string& fName, const std::string& lName, const std::string& nickName,
                    const std::string& phone, const std::string& secret);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

    void display() const;
};

class PhoneBook {
private:
    static const int maxContacts = 8;
    Contact contacts[maxContacts];
    int len;

public:
    PhoneBook();
    ~PhoneBook();

    void add();
    void search() const;

private:
    std::string truncate(const std::string &str) const;
};

#endif // PHONEBOOK_HPP