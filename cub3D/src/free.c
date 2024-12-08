/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:54:49 by ppezzull          #+#    #+#             */
/*   Updated: 2024/11/30 15:54:55 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_free(t_data *data)
{
	free_texture(&data->north_texture);
	free_texture(&data->south_texture);
	free_texture(&data->west_texture);
	free_texture(&data->east_texture);
	if (data->map.map)
		free_matrix(data->map.map);
	if (data->mlx.img)
		mlx_destroy_image(data->mlx.mlx_ptr, data->mlx.img);
	if (data->mlx.win_ptr)
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	if (data->mlx.mlx_ptr)
	{
		mlx_destroy_display(data->mlx.mlx_ptr);
		free(data->mlx.mlx_ptr);
	}
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	free_texture(t_texture *texture)
{
	int	i;

	i = 0;
	if (texture->path)
		free(texture->path);
	if (texture->color_table)
	{
		while (i < texture->colors_num)
			free(texture->color_table[i++].symbol);
		free(texture->color_table);
	}
	if (texture->color_matrix)
	{
		i = 0;
		while (texture->color_matrix[i])
			free(texture->color_matrix[i++]);
		free(texture->color_matrix);
	}
}
