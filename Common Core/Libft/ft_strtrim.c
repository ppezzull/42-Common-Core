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

int	trimmed_len(char const *s, char const *set)
{
	int	i;
	int	j;
	int	n_set;

	i = 0;
	n_set = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i + j] == set[j] && s[i + j] != '\0')
		{
			if (set[j + 1] == '\0')
				n_set++;
			j++;
		}
		i++;
	}
	return (i - n_set * ft_strlen(set));
}

int	is_set(char const *s, char const *set, int i)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (set[j] != s[i])
			return (0);
		j++;
		i++;
	}
	return (ft_strlen((char *)set));
}

char	*ft_strtrim(char const *s, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	if (!set)
		return (ft_strdup(s));
	if (!s)
		return (NULL);
	len = trimmed_len(s, set);
	str = (char *)malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		while (is_set(s, set, j))
			j += ft_strlen(s);
		str[i] = s[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
