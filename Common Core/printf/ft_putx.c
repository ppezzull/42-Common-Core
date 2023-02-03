/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:56:02 by ppezzull          #+#    #+#             */
/*   Updated: 2023/02/03 19:57:59 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putx(unsigned int n)
{
	int		len;
	int		i;
	int		temp;
	char	*hex_nbr;

	if (n == 0)
		return (ft_putchar('0'));
	len = ft_get_hex_len(n);
	i = len;
	hex_nbr = malloc(len * sizeof(char));
	if (!hex_nbr)
		return (0);
	while (i--)
	{
		temp = n % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		hex_nbr[i] = temp;
		n = n / 16;
	}
	ft_putstr(hex_nbr);
	free(hex_nbr);
	return (len);
}
