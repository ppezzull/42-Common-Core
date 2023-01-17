/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:33:53 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/16 21:34:05 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>

void ft_bzero(void *s, size_t n)
{
    int i;
    char* c;

    i = 0;
    c = s;
    while(i < n)
    {
        c[i] = '\0';
        i++;
    }
}


// int main(int argc, char **argv)
// {
//     if (argc == 2)
//     {
//         printf("The string before bzero: %s\n", argv[1]);
//         ft_bzero(argv[1], strlen(argv[1]));
//         printf("The string after bzero: %s", argv[1]);
//     }
//     printf("\n");
// }
