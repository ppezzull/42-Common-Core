/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:51:13 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/16 19:51:16 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int ft_isalnum(int letter)
{
    return(letter >= 'a' & letter <= 'z' || letter >= 'A' & letter <= 'Z' ) || (letter >= '1' & letter <= '9');
}

// int main()
// {
//     int test = 999;
//     printf("%i\n", ft_isalnum(test));
//     printf("%i", ft_isalnum(test));
//     printf("\n");
// }
