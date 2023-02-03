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

int	ft_putchar(int c)
{
    write(1, &c, 1);
    return (1);
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
	return (i);
}

int	    ft_putnbr(int n)
{
    ft_putnbr_script(n);
    return (ft_nbr_len(n));
}

int	ft_putuint(unsigned int n)
{
    ft_putuint_script(n);
    return (ft_uint_len(n));
}
