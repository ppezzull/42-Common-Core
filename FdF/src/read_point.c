/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:44:53 by ppezzull          #+#    #+#             */
/*   Updated: 2023/11/04 14:44:55 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

unsigned int	hex_string_to_value(const char *hexString)
{
	unsigned int	result;
	unsigned int	digit_value;
	int				i;
	char			c;

	result = 0;
	i = 0;
	if (hexString[0] == '0' && (hexString[1] == 'x' || hexString[1] == 'X'))
		i = 2;
	while (hexString[i] != '\0')
	{
		c = hexString[i];
		digit_value = 0;
		if (c >= '0' && c <= '9')
			digit_value = c - '0';
		else if (c >= 'A' && c <= 'F')
			digit_value = 10 + c - 'A';
		else if (c >= 'a' && c <= 'f')
			digit_value = 10 + c - 'a';
		result = (result << 4) | digit_value;
		i++;
	}
	return (result);
}

void	read_point(char *point, t_point *a)
{
	char	**info;
	char	*color_str;

	if (ft_strchr(point, ','))
	{
		info = ft_split(point, ',');
		a->z = ft_atoi(info[0]);
		color_str = info[1];
		a->color = hex_string_to_value(color_str);
		free(info[0]);
		free(info[1]);
		free(info);
	}
	else
	{
		a->color = LIGHT_PURPLE;
		a->z = ft_atoi(point);
	}
}
