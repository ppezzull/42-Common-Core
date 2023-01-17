/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:27:38 by ppezzull          #+#    #+#             */
/*   Updated: 2022/10/24 19:31:08 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

void	helper_capitalize(char *str, int i, int check)
{
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' & str[i] <= 'z' || str[i] >= '0' & str[i] <= '9')
		{
			if (check)
			{
				check = 0;
				if (str[i] >= 'a' && str[i] <= 'z')
					str[i] -= 32;
			}
		}
		else
			check = 1;
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		check;

	str = ft_strlowcase(str);
	i = 0;
	check = 0;
	if (str[0] >= 'a' && str[0] <= 'z')
	{	
		str[0] -= 32;
		i++;
	}
	helper_capitalize(str, i, check);
	return (str);
}
