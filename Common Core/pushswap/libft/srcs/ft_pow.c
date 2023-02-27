/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pietro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:41:21 by pietro            #+#    #+#             */
/*   Updated: 2023/02/24 12:41:23 by pietro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

int	ft_pow(int base, int exponent)
{
	int	n;

	n = base;
	if (exponent == 0)
		return (1);
	exponent--;
	while (exponent--)
		n *= base;
	return (n);
}