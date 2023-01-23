/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:01:20 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/21 12:01:22 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	substr = (char *)malloc(len * sizeof(char) + 1);
	if (!substr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i == start)
		{
			while (j < len && s[i + j] != '\0')
			{
				substr[j] = s[i + j];
				j++;
			}
			break ;
		}
		i++;
	}
	substr[j] = '\0';
	return (substr);
}
