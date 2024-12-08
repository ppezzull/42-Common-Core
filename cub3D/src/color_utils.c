/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:59:10 by ppezzull          #+#    #+#             */
/*   Updated: 2024/11/27 02:59:13 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	hex_char_to_int(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else
		return (-1);
}

char	**ft_strtrim_split_args(char **strs, char *set)
{
	int		i;
	char	*tmp;

	i = 0;
	while (strs[i])
	{
		tmp = strs[i];
		strs[i] = ft_strtrim(strs[i], set);
		free(tmp);
		i++;
	}
	return (strs);
}

int	ft_isdigit_split_args(char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (strs[i] && strs[i][0])
	{
		j = 0;
		while (strs[i][j])
		{
			if (!ft_isdigit(strs[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
}
