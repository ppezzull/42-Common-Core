/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 07:21:05 by ppezzull          #+#    #+#             */
/*   Updated: 2023/09/23 07:21:07 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


void	draw_line(t_point *param, t_point a, t_point b)
{
	float	step_x;
	float	step_y;
	float	max;

	transform_points(&a, &b, param);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = get_max(fmodule(step_x), fmodule(step_y));
	step_x /= max;
	step_y /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, a.x, a.y, a.color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
	}
}

void	draw_fdf(t_point **matrix)
{
	t_point	*param;
	int		y;
	int		x;

	param = &matrix[0][0];
	fdf_put_string(param);
	y = -1;
	while (matrix[y++ + 1])
	{
		x = 0;
		while (!matrix[y][x++].is_last)
		{
			if (matrix[y + 1])
				draw_line(param, matrix[y][x], matrix[y + 1][x]);
			if (!matrix[y][x].is_last)
				draw_line(param, matrix[y][x], matrix[y][x + 1]);
		}
	}
}
