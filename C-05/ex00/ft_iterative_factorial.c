/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:45:05 by ppezzull          #+#    #+#             */
/*   Updated: 2022/10/30 12:45:39 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	num;

	i = 2;
	num = 1;
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		num *= i;
		i++;
	}
	return (num);
}

// int main()
// {
//     printf ("%i",ft_iterative_factorial(5));
//     return 0;
// }
