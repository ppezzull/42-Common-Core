/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:26:31 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/16 19:26:36 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strlen(char* str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}

// int main(int argc, char** argv)
// {
//     if (argc == 2)
//     {
//         printf("%i", ft_strlen(argv[1]));
//     }
//     printf("\n");
// }