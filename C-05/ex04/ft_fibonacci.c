/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:50:14 by ppezzull          #+#    #+#             */
/*   Updated: 2022/10/30 12:56:27 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	int	out;

	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	if (index > 1)
	{
		out = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
		return (out);
	}
	else
		return (-1);
}

// int main()
// {
//     printf("res: %i", ft_fibonacci(4));
// }
