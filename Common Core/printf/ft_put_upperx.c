/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pietro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:56:53 by pietro            #+#    #+#             */
/*   Updated: 2023/02/03 08:56:55 by pietro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_hex_len(unsigned long long n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_put_upperx(unsigned int n)
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
			temp = temp + 55;
		hex_nbr[i] = temp;
		n = n / 16;
	}
	ft_putstr(hex_nbr);
	free(hex_nbr);
	return (len);
}
