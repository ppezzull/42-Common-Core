/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:38:22 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/31 18:38:23 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	unsigned char	c2;

	c2 = (unsigned char)c;
	write(1, &c2, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	if (nb >= 0)
	{
		if (nb <= 9)
		{
			ft_putchar(nb + '0');
			return 
		}
		else
		{
			ft_putnbr(nb / 10);
			ft_putchar(nb % 10 + '0');
		}
	}
	else
	{
		if (nb == -2147483648)
			write(1, "-2147483648", 11);
		else
		{
			write(1, "-", 1);
			ft_putnbr(nb * -1);
		}
	}
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i - 1);
}

int	ft_putuint(unsigned int n)
{
	if (n < 0)
		ft_putnbr(4294967296 - n);
}
