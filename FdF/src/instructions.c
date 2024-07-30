/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:14:06 by ppezzull          #+#    #+#             */
/*   Updated: 2023/10/11 14:14:09 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_put_string(t_point *param)
{
	mlx_string_put(param->mlx_ptr, param->win_ptr, 10, 20, DARK_PURPLE,
		"ppezzull FDF");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 10, 40, DARK_PURPLE,
		"ESC       ->    quit program");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 10, 60, DARK_PURPLE,
		"WASD      ->    move the projection around");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 10, 80, DARK_PURPLE,
		"I         ->    isometric projection");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 10, 100, DARK_PURPLE,
		"O         ->    top view");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 10, 120, DARK_PURPLE,
		"P         ->    perspective view");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 10, 140, DARK_PURPLE,
		"UP / DOWN ->    scale the projection");
}
