/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:45:35 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/21 11:45:38 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

#include "libft.h"

int	get_len(int n, int overflow)
{
	int	len;

	if (n == 0)
		return (1);
	if (overflow)
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

void	convert(char *str, int n, int i, int overflow)
{
	int	is_negative;
	int	len;

	len = get_len(n, overflow);
	if (overflow)
		n = -2147483647;
	is_negative = 0;
	if (n < 0)
	{
		n *= -1;
		is_negative = 1;
	}
	while (len--)
	{
		if (overflow && len == 10)
			str[len] = (n % 10) + '1';
		else
			str[len] = (n % 10) + '0';
		n = (n - (n % 10)) / 10;
		i++;
	}
	if (is_negative)
		str[0] = '-';
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	int		overflow;
	char	*str;

	overflow = 0;
	if (n == -2147483648)
		overflow = 1;
	len = get_len(n, overflow);
	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	convert(str, n, i, overflow);
	return (str);
}
