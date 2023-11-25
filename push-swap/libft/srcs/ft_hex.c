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

int	ft_hex(unsigned int nb, char *hex, unsigned int base)
{
	int	len;

	len = 0;
	if (nb >= base)
		len += ft_hex(nb / base, hex, base);
	len += ft_putchar(hex[nb % base]);
	return (len);
}
