/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_useful_scripts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pezzu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 06:16:28 by pezzu             #+#    #+#             */
/*   Updated: 2023/02/03 19:52:48 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbr_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_script(int nb)
{
	if (nb >= 0)
	{
		if (nb <= 9)
		{
			ft_putchar(nb + '0');
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
