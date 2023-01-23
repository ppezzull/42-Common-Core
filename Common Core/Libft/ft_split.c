/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:34:03 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/21 11:34:04 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	charset_len(char *s, char c, int i)
{
	if (s[i] == c)
		return (1 + charset_len(s, c, i + 1));
	return (0);
}

int	n_of_words(char *s, char c)
{
	int	i;
	int	words;
	int	found;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		found = charset_len(s, c, i);
		if (found)
			i += found;
		else
		{
			while (!charset_len(s, c, i) && s[i] != '\0')
				i++;
			words++;
		}
	}
	return (words);
}

char	*get_word(char *str, int start, int end)
{
	int		len;
	int		i;
	char	*word;

	len = end - start;
	word = malloc(len * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		n_words;
	int		i;
	int		j;
	int		start;

	n_words = n_of_words((char *)s, c);
	split = malloc(n_words * sizeof(char) + 1);
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (i < n_words)
	{
		j += charset_len((char *)s, c, j);
		start = j;
		while (!charset_len((char *)s, c, j) && s[j] != '\0')
			j++;
		split[i] = get_word((char *)s, start, j);
		i++;
	}
	split[i] = 0;
	return (split);
}
