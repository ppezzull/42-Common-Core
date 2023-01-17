/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isidigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:58:37 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/16 16:58:52 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int ft_isdigit(int letter)
{
    return (letter >= '1' & letter <= '9');
}

// int main()
// {
//     int test = 194;
//     printf("%i\n", ft_isdigit(test));
//     printf("%i\n", isdigit(test));
// }
