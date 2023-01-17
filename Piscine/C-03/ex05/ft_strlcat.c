/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:25:04 by ppezzull          #+#    #+#             */
/*   Updated: 2022/10/27 13:25:29 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	i = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0' && i < size -1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[j]));
}

// int		main(void)
// {
// 	char dest[20] = "123";
// 	char src[] = "4567890";
// 	unsigned int size = 6;
// 	unsigned int result;

// 	printf("dest = %s\nsrc = %s\nnb = %d\n\n", dest, src, size);
// 	result = ft_strlcat(dest, src, size);
// 	printf("dest (cat) = %s\nresult = %d\n", dest, result);

// 	return (0);
// }
