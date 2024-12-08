/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <rilliano@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:59:38 by ppezzull          #+#    #+#             */
/*   Updated: 2024/12/03 10:27:42 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(t_data *data)
{
	int			x;
	int			y;
	t_minimap	minimap;

	init_minimap(data, &minimap);
	draw_map_background(data, &minimap);
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (data->map.map[y][x] != '\0')
		{
			if (data->map.map[y][x] == '1')
				draw_square(data, x, y, &minimap);
			x++;
		}
		y++;
	}
	draw_player(data, &minimap);
}

void	init_minimap(t_data *data, t_minimap *minimap)
{
	minimap->size = 12;
	minimap->background_color = 0xADD8E6;
	minimap->wall_color = 0x000040;
	minimap->player_color = 0xFF0000;
	minimap->x_center = data->player.x * (double)minimap->size + minimap->size;
	minimap->y_center = data->player.y * (double)minimap->size + minimap->size;
	minimap->radius = minimap->size / 4;
}

void	draw_square(t_data *data, int x, int y, t_minimap *minimap)
{
	int	i;
	int	j;

	x = x * minimap->size + minimap->size;
	y = y * minimap->size + minimap->size;
	i = 0;
	while (i < minimap->size)
	{
		j = 0;
		while (j < minimap->size)
		{
			if (x + j > data->mlx.img_width || y + i > data->mlx.img_height
				|| x < 0 || y < 0)
				break ;
			data->mlx.img_addr[(y + i) * data->mlx.img_width + (x
					+ j)] = minimap->wall_color;
			j++;
		}
		i++;
	}
}

void	draw_player(t_data *data, t_minimap *minimap)
{
	int	x;
	int	y;

	x = -minimap->radius;
	while (x <= minimap->radius)
	{
		y = -minimap->radius;
		while (y <= minimap->radius)
		{
			if (minimap->x_center + x >= 0 && minimap->x_center
				+ x < data->mlx.img_width && minimap->y_center + y >= 0
				&& minimap->y_center + y < data->mlx.img_height && x * x + y
				* y <= minimap->radius * minimap->radius)
			{
				data->mlx.img_addr[(minimap->y_center + y) * data->mlx.img_width
					+ (minimap->x_center + x)] = minimap->player_color;
			}
			y++;
		}
		x++;
	}
}

void	draw_map_background(t_data *data, t_minimap *minimap)
{
	int	x;
	int	y;

	y = minimap->size - minimap->size / 3;
	while (y < data->map.height * minimap->size + minimap->size + minimap->size
		/ 3)
	{
		x = minimap->size - minimap->size / 3;
		while (x < data->map.width * minimap->size + minimap->size
			+ minimap->size / 3)
		{
			if (x >= 0 && x < data->mlx.img_width && y >= 0
				&& y < data->mlx.img_height)
			{
				data->mlx.img_addr[y * data->mlx.img_width
					+ x] = minimap->background_color;
			}
			x++;
		}
		y++;
	}
}
