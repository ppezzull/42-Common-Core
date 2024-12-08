/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 03:00:50 by ppezzull          #+#    #+#             */
/*   Updated: 2024/11/27 03:00:52 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_elements(t_data *data)
{
	check_textures(data);
	check_colors(data);
	return (0);
}

int	check_colors(t_data *data)
{
	if (data->floor_color == -1 || data->ceiling_color == -1)
		handle_error(data, ENOEXEC, "Invalid map.\tMissing color before map.");
	return (0);
}

int	check_textures(t_data *data)
{
	if (data->north_texture.path == NULL || data->south_texture.path == NULL
		|| data->west_texture.path == NULL || data->east_texture.path == NULL)
		handle_error(data, ENOEXEC,
			"Invalid map.\tMissing texture before map.");
	if (check_texture_format(data->north_texture.path) == 1)
		handle_error(data, ENOEXEC,
			"Invalid texture.\tTexture format not supported.");
	if (check_texture_format(data->south_texture.path) == 1)
		handle_error(data, ENOEXEC,
			"Invalid texture.\tTexture format not supported.");
	if (check_texture_format(data->west_texture.path) == 1)
		handle_error(data, ENOEXEC,
			"Invalid texture.\tTexture format not supported.");
	if (check_texture_format(data->east_texture.path) == 1)
		handle_error(data, ENOEXEC,
			"Invalid texture.\tTexture format not supported.");
	return (0);
}

int	check_texture_format(char *path)
{
	if (ft_strncmp(path + ft_strlen(path) - 4, ".xpm", 4) != 0)
		return (1);
	return (0);
}

int	check_file_path(t_data *data, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		handle_error(data, errno, "Failed to open texture file.");
	close(fd);
	return (0);
}
