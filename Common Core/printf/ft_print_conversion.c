/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:39:46 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/31 19:39:48 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_conversion(const char *out, int i, va_list artgptr)
{
	i++;
	if (out[i] == '\0')
		return (0);
	if (out[i] == 'c')
		return (ft_putchar(va_arg(artgptr, unsigned int)));
	if (out[i] == 's')
		return (ft_putstr(va_arg(artgptr, char *)));
	if (out[i] == 'i' || out[i] == 'd')
		return (ft_putnbr(va_arg(artgptr, int)));
	if (out[i] == '%')
		return (ft_putchar('%'));
	if (out[i] == 'u')
		return (ft_putuint(va_arg(artgptr, unsigned int)));
}
