/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:03:56 by ppezzull          #+#    #+#             */
/*   Updated: 2023/02/03 04:03:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_conversion(char flag, va_list *ap)
{
	if (flag == '\0')
		return (0);
	if (flag == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	if (flag == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	if (flag == 'i' || flag == 'd')
		return (ft_putnbr(va_arg(*ap, int)));
	if (flag == '%')
		return (ft_putchar('%'));
	if (flag == 'u')
		return (ft_putuint(va_arg(*ap, unsigned int)));
    else
        return (0);
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
		{
            print_len += ft_putchar(out[i]);
		}
		i++;
	}
	va_end(ap);
	return (print_len);
}
