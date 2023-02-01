/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:03:56 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/31 17:03:57 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *out, ...)
{
	va_list	artgptr;
	int		i;
	int		print_len;

	va_start(artgptr, out);
	print_len = 0;
	i = 0;
	while (out[i])
	{
		if (out[i] == '%')
		{
			ft_print_conversion(out, i, artgptr);
			i++;
		}
		else
		{
			ft_putchar(out[i]);
		}
		i++;
	}
	va_end(artgptr);
	return (i - 1);
}
