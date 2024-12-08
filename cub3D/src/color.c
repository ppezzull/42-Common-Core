/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:54:40 by ppezzull          #+#    #+#             */
/*   Updated: 2024/11/27 02:54:47 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color_from_rgb_str(char *str)
{
	char	**rgb;
	int		color;

	rgb = ft_split(str, ',');
	ft_strtrim_split_args(rgb, " \n\t\v\f\r");
	if (ft_isdigit_split_args(rgb) != 3)
		return (-1);
	color = get_color_from_rgb_array(rgb);
	free_matrix(rgb);
	return (color);
}

unsigned int	get_color_from_rgb_array(char **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (r << 16 | g << 8 | b);
}

unsigned int	ft_atoi_hex(char *str)
{
	int	res;
	int	value;

	res = 0;
	while (*str != '#')
		str++;
	str++;
	while (*str)
	{
		value = hex_char_to_int(*str);
		if (value == -1)
			break ;
		res = (res << 4) | value;
		str++;
	}
	return (res);
}

unsigned int	get_color_by_symbol(t_texture *texture, char *symbol)
{
	int	i;

	i = 0;
	while (i < texture->colors_num)
	{
		if (ft_strncmp(texture->color_table[i].symbol, symbol,
				texture->char_per_pixel) == 0)
			return (texture->color_table[i].color);
		i++;
	}
	return (-1);
}

unsigned int	*get_color_row(t_data *data, t_texture *texture, char *line)
{
	unsigned int	*row;
	int				i;

	row = ft_calloc(sizeof(unsigned int), texture->width + 1);
	if (!row)
		handle_error(data, ENOMEM, "Failed to allocate memory.");
	i = 0;
	while (i < texture->width)
	{
		row[i] = get_color_by_symbol(texture, line + i * texture->char_per_pixel
				+ 1);
		i++;
	}
	i = 0;
	return (row);
}
