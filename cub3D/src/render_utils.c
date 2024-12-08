/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:51:32 by ppezzull          #+#    #+#             */
/*   Updated: 2024/11/27 16:51:34 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycast(t_raycast *raycast, t_data *data, int x, int w)
{
	raycast->camera_x = 2 * x / (double)w - 1;
	raycast->ray_x = data->player.dir_x + data->player.plane_x
		* raycast->camera_x;
	raycast->ray_y = data->player.dir_y + data->player.plane_y
		* raycast->camera_x;
	raycast->map_x = (int)data->player.x;
	raycast->map_y = (int)data->player.y;
	raycast->delta_x = fabs(1 / raycast->ray_x);
	raycast->delta_y = fabs(1 / raycast->ray_y);
	raycast->hit = 0;
}

void	calculate_wall_params(t_raycast *raycast, t_data *data, int h)
{
	if (raycast->side == 0)
	{
		raycast->wall_dist = (raycast->map_x - data->player.x + (1
					- raycast->step_x) / 2) / raycast->ray_x;
	}
	else
	{
		raycast->wall_dist = (raycast->map_y - data->player.y + (1
					- raycast->step_y) / 2) / raycast->ray_y;
	}
	raycast->line_h = (int)(h / raycast->wall_dist);
	raycast->draw_start = -raycast->line_h / 2 + h / 2;
	raycast->draw_end = raycast->line_h / 2 + h / 2;
	if (raycast->draw_start < 0)
		raycast->draw_start = 0;
	if (raycast->draw_end >= h)
		raycast->draw_end = h - 1;
}

void	fill_ceiling_and_floor(t_data *data, int w, int h)
{
	int	y;
	int	x;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (y < h / 2)
				data->mlx.img_addr[y * w + x] = data->ceiling_color;
			else
				data->mlx.img_addr[y * w + x] = data->floor_color;
			x++;
		}
		y++;
	}
}

void	calculate_texture_params(t_data *data, t_raycast *raycast, int h)
{
	if (raycast->side == 1 && raycast->ray_y < 0)
		raycast->texture = &data->north_texture;
	else if (raycast->side == 1 && raycast->ray_y > 0)
		raycast->texture = &data->south_texture;
	else if (raycast->side == 0 && raycast->ray_x < 0)
		raycast->texture = &data->west_texture;
	else
		raycast->texture = &data->east_texture;
	raycast->wall_x -= floor(raycast->wall_x);
	raycast->tex_x = (int)(raycast->wall_x * (double)raycast->texture->width);
	if (raycast->side == 0 && raycast->ray_x > 0)
		raycast->tex_x = raycast->texture->width - raycast->tex_x - 1;
	if (raycast->side == 1 && raycast->ray_y < 0)
		raycast->tex_x = raycast->texture->width - raycast->tex_x - 1;
	raycast->step = 1.0 * raycast->texture->height / raycast->line_h;
	raycast->tex_pos = (raycast->draw_start - h / 2 + raycast->line_h / 2)
		* raycast->step;
}

void	render_column(t_data *data, t_raycast *raycast, int w, int x)
{
	int	y;

	y = raycast->draw_start;
	while (y < raycast->draw_end)
	{
		raycast->tex_y = (int)raycast->tex_pos & (raycast->texture->height - 1);
		raycast->tex_pos += raycast->step;
		raycast->color = raycast
			->texture->color_matrix[raycast->tex_y][raycast->tex_x];
		if (raycast->side == 1)
			raycast->color = (raycast->color >> 1) & 0x7F7F7F;
		data->mlx.img_addr[y * w + x] = raycast->color;
		y++;
	}
}
