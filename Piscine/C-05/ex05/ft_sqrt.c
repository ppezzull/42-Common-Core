/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:51:03 by ppezzull          #+#    #+#             */
/*   Updated: 2022/11/01 18:45:13 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;
	int	res;

	i = 0;
	while (i <= (nb / 2) + 1)
	{
		res = i * i;
		if (res == nb)
			return (i);
		else if (res > nb)
			return (0);
		else
			i++;
	}
	return (0);
}

// int main()
// {
//     printf("res: %i", ft_sqrt(0));
// }
