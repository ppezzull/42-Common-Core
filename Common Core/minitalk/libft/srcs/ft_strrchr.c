/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:37:37 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/20 17:37:39 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (str[i] != '\0')
	{
		if (str[len - i] == (unsigned char)ch)
			return ((char *)str + (len - i));
		i++;
	}
	if (str[len - i] == (unsigned char)ch)
		return ((char *)str + (len - i));
	return (NULL);
}
