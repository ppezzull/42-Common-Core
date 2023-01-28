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
	int	len_s;
	int	len_set;
	int	len;

	i = 0;
	len = ft_strlen(s);
	len_s = ft_strlen(s);
	len_set = ft_strlen(set);
	while (i < len_s)
    {
        if (i < len_set || i >= len_s - len_set)
        {
            if (is_trim(s[i], set))
                len--;
        }
        i++;
    }
	return (len);
}

void    get_trim(char *str, int len, char const *s, char const *set)
{
    int	i;
    int	j;
	int	len_s;
	int	len_set;
	
	i = 0;
    j = 0;
	len_s = ft_strlen(s);
	len_set = ft_strlen(set);
    str[len] = '\0';
	while (i < len_s)
    {
        if (i < len_set || i >= len_s - len_set)
        {
            if (is_trim(s[i], set))
            {
                i++;
                continue ;
            }
        }
        str[j] = s[i];
        i++;
        j++;
    }
}

char	*ft_strtrim(char const *s, char const *set)
{
	int		i;
	int		len;
	char	*str;

    len = trimmed_len(s, set);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
    get_trim(str, len, s, set);
	return (str);
}
