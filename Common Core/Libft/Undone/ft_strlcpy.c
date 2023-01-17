/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:11:18 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/17 20:14:21 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	i = 0;
	while (i < size && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i == ft_strlen(dst))
		dst[i] = '\0';
	else
		dst[ - 1] = '\0';
	return (ft_strlen(dst));
}

int	main(int argc, char	**argv)
{
	char	*src;
	char	*dest;
	int		n;

	dest = argv[1];
	src = argv[2];
	printf("%zu\n", ft_strlcpy(dest, src, ft_strlen(src)));
	printf("%s\n", dest);
}
