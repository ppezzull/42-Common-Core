/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:29:54 by ppezzull          #+#    #+#             */
/*   Updated: 2023/11/04 13:29:56 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	transform_points(t_point *a, t_point *b, t_point *param)
{
	zoom(a, b, param);
	if (param->is_isometric == 1)
	{
		isometric(a, param->angle);
		isometric(b, param->angle);
	}
	a->x += param->shift_x;
	a->y += param->shift_y;
	b->x += param->shift_x;
	b->y += param->shift_y;
}

void	zoom(t_point *a, t_point *b, t_point *param)
{
	if (a->z != 0)
		a->z += param->z_scale;
	if (b->z != 0)
		b->z += param->z_scale;
	a->x *= param->scale;
	a->y *= param->scale;
	b->x *= param->scale;
	b->y *= param->scale;
	a->z *= param->scale;
	b->z *= param->scale;
}

void	isometric(t_point *point, double angle)
{
	point->x = (point->x - point->y) * cos(angle);
	point->y = (point->x + point->y) * sin(angle) - point->z;
}
