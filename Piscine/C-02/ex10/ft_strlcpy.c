/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:31:34 by ppezzull          #+#    #+#             */
/*   Updated: 2022/10/24 22:59:05 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	l;

	i = 0;
	l = 0;
	while (src[l])
		l++;
	if (size != 0)
	{
		while (src[i] && i <= size -2)
		{
			dest[i] = src[i];
			i++;
		}
		while (dest[i])
		{
			dest[i] = 0;
			i++;
		}
	}
	return (l);
}

int	main()
{
	char a[50] = "a";
	char b[50] = "s";
	printf("%i-%s-%s\n", ft_strlcpy(a , b, 8),a,b);
	printf("%lu-%s-%s\n", strlcpy(a , b, 8),a,b);
}