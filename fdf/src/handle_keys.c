/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:19:42 by ppezzull          #+#    #+#             */
/*   Updated: 2023/09/23 00:19:47 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	is_key(int key)
{
	return (key == KEY_N || key == KEY_M || key == KEY_UP || key == KEY_DOWN
		|| key == KEY_I || key == KEY_O || key == KEY_W || key == KEY_A
		|| key == KEY_S || key == KEY_D || key == KEY_P);
}

void	run_translation_keys(int key, t_point *param)
{
	if (key == KEY_I)
	{
		param->is_isometric = 1;
		param->angle = 0.54;
	}
	if (key == KEY_P)
	{
		param->is_isometric = 1;
		param->angle = 0;
	}
}

void	run_movement_key(int key, t_point *param)
{
	if (key == KEY_UP)
		param->scale += 2;
	if (key == KEY_DOWN)
		param->scale -= 2;
	if (key == KEY_O)
		param->is_isometric = 0;
	if (key == KEY_W)
		param->shift_y -= 10;
	if (key == KEY_A)
		param->shift_x -= 10;
	if (key == KEY_S)
		param->shift_y += 10;
	if (key == KEY_D)
		param->shift_x += 10;
	if (key == KEY_M)
		param->z_scale += 1;
	if (key == KEY_N)
		param->z_scale -= 1;
}

int	run_key(int key, t_point *param)
{
	run_movement_key(key, param);
	run_translation_keys(key, param);
	return (is_key(key));
}

int	handle_keys(int key, t_point **matrix)
{
	t_point	*param;

	param = &matrix[0][0];
	if (key == KEY_ESC)
	{
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		mlx_destroy_display(param->mlx_ptr);
		free(param->mlx_ptr);
		free_matrix(matrix);
		exit(0);
	}
	if (run_key(key, param))
	{
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		draw_fdf(matrix);
	}
	return (0);
}
