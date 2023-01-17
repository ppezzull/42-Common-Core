/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:06:48 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/16 20:06:54 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int ft_isprint(char letter)
{
    if (letter >= 33 & letter <= 126)
        return (1);
    return (0);
}

// int main()
// {
//     int test = 999;
//     printf("%i\n", ft_isprint(test));
//     printf("%i", isprint(test));
//     printf("\n");
// }
