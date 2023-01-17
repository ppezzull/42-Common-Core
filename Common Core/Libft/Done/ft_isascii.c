/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:01:32 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/16 20:01:35 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_isascii(char letter)
{
    return (letter >= 0 & letter <= 127);
}

// int main()
// {
//     int test = '\t';
//     printf("%i\n", ft_isascii(test));
//     printf("%i", ft_isascii(test));
//     printf("\n");
// }
