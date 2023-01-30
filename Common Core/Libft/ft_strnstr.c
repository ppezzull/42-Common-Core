/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:38:09 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/20 17:38:11 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strncmp(to_find, "", ft_strlen(to_find)) == 0)
		return ((char *)str);
	if ((!to_find || !str) && !len)
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j]
			&& str[i + j] && (i + j) < len)
		{
			if (i + j > len)
				break ;
			j++;
		}
		if (to_find[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
