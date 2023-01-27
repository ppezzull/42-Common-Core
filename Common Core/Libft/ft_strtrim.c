/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:31:12 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/21 11:31:17 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_trim(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	trimmed_len(char const *s, const char *set)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (set[i])
	{
		if (is_trim(s[i], set))
			len--;
		i++;
	}
	return (len);
}

char	*ft_strtrim(char const *s, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	len = trimmed_len(s, set);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (j < len)
	{
		if (!is_trim(s[i], set))
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	return (str);
}
