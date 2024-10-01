/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 04:39:09 by ppezzull          #+#    #+#             */
/*   Updated: 2024/08/06 04:39:13 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "ADD a contact, SEARCH one or EXIT the program\n";
        std::getline(std::cin, command);
        if (std::cin.eof())
        {
            std::cout << "\n";
            exit(EXIT_FAILURE);
        }
        else if (command == "ADD")
            phoneBook.add();
        else if (command == "SEARCH")
            phoneBook.search();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Put a valid command OG\n";
        command = "";
    }

    return (0);
}
