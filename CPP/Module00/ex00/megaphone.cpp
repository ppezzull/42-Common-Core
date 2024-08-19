/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 03:15:49 by ppezzull          #+#    #+#             */
/*   Updated: 2024/08/06 03:15:52 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv) 
{
    if (argc == 1) 
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl; 
    else 
    {
        for (int i = 1; i < argc; ++i) 
        {
            for (int j = 0; argv[i][j]; ++j) 
            {
                if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
                    std::cout << (char)toupper(argv[i][j]);
                else
                    std::cout << argv[i][j];
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
