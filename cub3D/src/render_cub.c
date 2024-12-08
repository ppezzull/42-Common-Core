/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <rilliano@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 03:00:35 by ppezzull          #+#    #+#             */
/*   Updated: 2024/11/30 21:47:00 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_step_and_side(t_raycast *raycast, t_data *data)
{
	if (raycast->ray_x < 0)
	{
		raycast->step_x = -1;
		raycast->side_x = (data->player.x - raycast->map_x)
			* raycast->delta_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->side_x = (raycast->map_x + 1.0 - data->player.x)
			* raycast->delta_x;
	}
	if (raycast->ray_y < 0)
	{
		raycast->step_y = -1;
		raycast->side_y = (data->player.y - raycast->map_y)
			* raycast->delta_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->side_y = (raycast->map_y + 1.0 - data->player.y)
			* raycast->delta_y;
	}
}

void	step_and_update_side_dist(t_raycast *raycast)
{
	if (raycast->side_x < raycast->side_y)
	{
		raycast->side_x += raycast->delta_x;
		raycast->map_x += raycast->step_x;
		raycast->side = 0;
	}
	else
	{
		raycast->side_y += raycast->delta_y;
		raycast->map_y += raycast->step_y;
		raycast->side = 1;
	}
}

void	perform_dda(t_raycast *raycast, t_data *data)
{
	while (!raycast->hit)
	{
		step_and_update_side_dist(raycast);
		if (data->map.map[raycast->map_y][raycast->map_x] == '1')
			raycast->hit = 1;
	}
}

void	render_wall_columns(t_data *data, int w, int h)
{
	int			x;
	t_raycast	raycast;

	x = 0;
	while (x < w)
	{
		init_raycast(&raycast, data, x, w);
		calculate_step_and_side(&raycast, data);
		perform_dda(&raycast, data);
		calculate_wall_params(&raycast, data, h);
		if (raycast.side == 0)
		{
			raycast.wall_x = data->player.y + raycast.wall_dist
				* raycast.ray_y;
		}
		else
		{
			raycast.wall_x = data->player.x + raycast.wall_dist
				* raycast.ray_x;
		}
		calculate_texture_params(data, &raycast, h);
		render_column(data, &raycast, w, x);
		x++;
	}
}

void	render_cub(t_data *data)
{
	int	w;
	int	h;

	w = data->mlx.img_width;
	h = data->mlx.img_height;
	fill_ceiling_and_floor(data, w, h);
	render_wall_columns(data, w, h);
}
