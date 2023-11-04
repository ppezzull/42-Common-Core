/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:53:48 by ppezzull          #+#    #+#             */
/*   Updated: 2023/09/22 19:53:53 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	error(char *message)
{
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void	set_default(t_point *point)
{
	point->z_scale = 0;
	point->scale = 20;
	point->is_isometric = 1;
	point->angle = 0.54;
	point->win_x = 1600;
	point->win_y = 900;
	point->shift_x = point->win_x / 2;
	point->shift_y = point->win_y / 2;
	point->mlx_ptr = mlx_init();
	point->win_ptr = mlx_new_window(point->mlx_ptr, point->win_x, point->win_y,
			"FDF");
}

int	main(int argc, char **argv)
{
	t_point	**matrix;
	t_point	*param;

	if (argc != 2)
		error("Put the fdf file bro");
	matrix = read_fdf(argv[1]);
	param = &matrix[0][0];
	set_default(param);
	draw_fdf(matrix);
	mlx_key_hook(param->win_ptr, handle_keys, matrix);
	mlx_loop(param->mlx_ptr);
}
