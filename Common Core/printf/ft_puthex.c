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

int    ft_uint_to_hex(int n)
{
	int     len;
	int     temp;

	while (n > 0) 
	{
		temp = n % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;
		ft_putchar(temp);
		n = n / 16;
		len++;
	}
	return (len);
}

int    ft_negint_to_hex(int n)
{
	char    temp;

	n = -n;
	while (i++ < 8 - ft_uint_len(n))
	{
		ft_putchar('F');
	}
	while (n > 0)
	{
		temp = n % 16;
		if (temp <= 6)
			temp = 'F' - temp;
		else
			temp = '9' + 6 - temp;
		ft_putchar(temp);
		n = n / 16;
	}
	return (8);	
}

int ft_put_uphex(int n)
{
	int len;
	
	if (n == -1)
		return (ft_putstr("FFFFFFFF"));
	else if (n >= 0)
		len = ft_uint_to_hex(n);
	else
		len = ft_negint_to_hex(n);
	return (len);
}