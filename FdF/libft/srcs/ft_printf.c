/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:03:56 by ppezzull          #+#    #+#             */
/*   Updated: 2023/02/03 14:51:01 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_conversion(char format, va_list *ap)
{
	if (format == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	if (format == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	if (format == 'i' || format == 'd')
		return (ft_putnbr(va_arg(*ap, int)));
	if (format == '%')
		return (ft_putchar('%'));
	if (format == 'p')
		return (ft_putptr(va_arg(*ap, unsigned long long)));
	if (format == 'u')
		return (ft_hex(va_arg(*ap, unsigned int), "0123456789", 10));
	if (format == 'x')
		return (ft_hex(va_arg(*ap, unsigned int), "0123456789abcdef", 16));
	if (format == 'X')
		return (ft_hex(va_arg(*ap, unsigned int), "0123456789ABCDEF", 16));
	else
		return (1);
}

int	ft_printf(const char *out, ...)
{
	va_list	ap;
	int		i;
	int		print_len;

	va_start(ap, out);
	print_len = 0;
	i = 0;
	while (out[i])
	{
		if (out[i] == '%')
		{
			print_len += ft_print_conversion(out[i + 1], &ap);
			i++;
		}
		else
			print_len += ft_putchar(out[i]);
		i++;
	}
	va_end(ap);
	return (print_len);
}
