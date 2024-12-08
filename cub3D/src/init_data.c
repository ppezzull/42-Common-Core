/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <rilliano@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 02:59:46 by ppezzull          #+#    #+#             */
/*   Updated: 2024/12/03 10:29:29 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->mlx.mlx_ptr = NULL;
	data->mlx.win_ptr = NULL;
	data->mlx.img = NULL;
	data->mlx.img_addr = NULL;
	data->mlx.img_width = 960;
	data->mlx.img_height = 720;
	data->map.map = NULL;
	data->map.width = 0;
	data->map.height = 0;
	data->player.x = 0.0;
	data->player.y = 0.0;
	data->pov = '0';
	data->player.speed = 0.2;
	data->player.rot_speed = 0.1;
	init_textures(data);
	data->floor_color = -1;
	data->ceiling_color = -1;
	data->player.dir_x = 1.0;
	data->player.dir_y = 0.0;
	data->player.plane_x = 0.0;
	data->player.plane_y = 0.66;
}

void	init_mlx(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	if (data->mlx.mlx_ptr == NULL)
		handle_error(data, EIO, "Failed to initialize mlx.");
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr, data->mlx.img_width,
			data->mlx.img_height, "cub3D");
	if (data->mlx.win_ptr == NULL)
		handle_error(data, EIO, "Failed to create window.");
	data->mlx.img = mlx_new_image(data->mlx.mlx_ptr, data->mlx.img_width,
			data->mlx.img_height);
	if (data->mlx.img == NULL)
		handle_error(data, EIO, "Failed to create image.");
}

void	init_texture(t_texture *texture)
{
	texture->width = 0;
	texture->height = 0;
	texture->colors_num = 0;
	texture->char_per_pixel = 0;
	texture->color_matrix = NULL;
	texture->path = NULL;
	texture->color_table = NULL;
}

void	init_textures(t_data *data)
{
	init_texture(&data->north_texture);
	init_texture(&data->south_texture);
	init_texture(&data->west_texture);
	init_texture(&data->east_texture);
}

int	set_image(t_data *data)
{
	t_mlx	*mlx;

	mlx = &data->mlx;
	if (mlx->img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx_ptr, mlx->img_width, mlx->img_height);
	mlx->img_addr = (int *)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_l,
			&mlx->endian);
	if (mlx->img_addr == NULL)
		handle_error(data, EIO, "Failed to get image address.");
	return (0);
}
