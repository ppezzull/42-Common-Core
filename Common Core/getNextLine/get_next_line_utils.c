/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pietro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:24:52 by pietro            #+#    #+#             */
/*   Updated: 2023/02/07 18:43:16 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		len;
	int		i;

	len = ft_strlen(src);
	copy = malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*united;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	united = (char *) malloc (sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (united == NULL)
		return (NULL);
	while (s1[j] != '\0')
		united[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		united[i++] = s2[j++];
	united[i] = '\0';
	free(s1);
	return (united);
}

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)ch)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == ch)
		return ((char *)str + i);
	return (NULL);
}
