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

int	get_len(int n)
{
	int	len;

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

void	convert(char *str, int n, int len, int i)
{
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n = (n - (n % 10)) / 10;
		i++;
	}
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*str;

	len = get_len(n);
	i = 0;
	if (n < 0)
	{
		n *= -1;
		str = malloc(sizeof(char) * (len + 2));
	}
	else
		str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	convert(str, n, len);
	return (str);
}
