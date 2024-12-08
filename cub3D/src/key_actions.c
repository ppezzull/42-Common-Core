/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <rilliano@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:59:54 by ppezzull          #+#    #+#             */
/*   Updated: 2024/11/30 21:12:32 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_exit(t_data *data)
{
	cub_free(data);
	exit(0);
}

int	resize_window(t_data *data, XEvent *event)
{
	XConfigureEvent	xce;

	if (event->type == ConfigureNotify)
	{
		xce = event->xconfigure;
		data->mlx.img_width = xce.width;
		data->mlx.img_height = xce.height;
	}
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == XK_w)
		move_player(data, 'W');
	else if (keycode == XK_s)
		move_player(data, 'S');
	else if (keycode == XK_a)
		move_player(data, 'A');
	else if (keycode == XK_d)
		move_player(data, 'D');
	else if (keycode == XK_Left)
		rotate_player(data, -1);
	else if (keycode == XK_Right)
		rotate_player(data, 1);
	else if (keycode == XK_Escape)
		cub_exit(data);
	return (0);
}

void	move_player(t_data *data, char dir)
{
	double	new_x;
	double	new_y;

	calculate_new_position(data, dir, &new_x, &new_y);
	if (data->map.map[(int)new_y][(int)new_x] != '1')
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
}

void	rotate_player(t_data *data, int dir)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rotate_angle;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	rotate_angle = dir * data->player.rot_speed;
	data->player.dir_x = data->player.dir_x * cos(rotate_angle)
		- data->player.dir_y * sin(rotate_angle);
	data->player.dir_y = old_dir_x * sin(rotate_angle) + data->player.dir_y
		* cos(rotate_angle);
	data->player.plane_x = data->player.plane_x * cos(rotate_angle)
		- data->player.plane_y * sin(rotate_angle);
	data->player.plane_y = old_plane_x * sin(rotate_angle)
		+ data->player.plane_y * cos(rotate_angle);
}
