/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexmem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:04:03 by ppezzull          #+#    #+#             */
/*   Updated: 2023/02/06 17:04:08 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_ptr(uintptr_t nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

void	ft_put_ptr(uintptr_t nb)
{
	if (nb >= 16)
	{
		ft_put_ptr(nb / 16);
		ft_put_ptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar((nb + '0'));
		else
			ft_putchar((nb - 10 + 'a'));
	}
}

int	ft_putptr(unsigned long long ptr)
{
	int	char_printed;

	char_printed = 0;
	char_printed += write(1, "0x", 2);
	if (ptr == 0)
		char_printed += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		char_printed += len_ptr(ptr);
	}
	return (char_printed);
}
