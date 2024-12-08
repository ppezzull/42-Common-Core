/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 03:00:28 by ppezzull          #+#    #+#             */
/*   Updated: 2024/11/27 03:00:30 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_textures(t_data *data)
{
	check_file_path(data, data->north_texture.path);
	check_file_path(data, data->south_texture.path);
	check_file_path(data, data->west_texture.path);
	check_file_path(data, data->east_texture.path);
	parse_texture_data(data, &data->north_texture);
	parse_texture_data(data, &data->south_texture);
	parse_texture_data(data, &data->west_texture);
	parse_texture_data(data, &data->east_texture);
	return (0);
}

int	parse_texture_data(t_data *data, t_texture *texture)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(texture->path, O_RDONLY);
	if (fd == -1)
		handle_error(data, errno, "Failed to open texture file.");
	i = 0;
	while (i < 2)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	line = get_next_line(fd);
	parse_texture_info(line, texture, data);
	free(line);
	parse_color_table(data, texture, fd);
	parse_color_matrix(data, texture, fd);
	close(fd);
	return (0);
}

void	parse_texture_info(char *line, t_texture *texture, t_data *data)
{
	char	**tmp;
	int		i;

	tmp = ft_split((line + 1), ' ');
	i = 0;
	while (i < 4)
	{
		if (!tmp[i])
			handle_error(data, ENOEXEC, "Invalid texture file.");
		i++;
	}
	texture->width = ft_atoi(tmp[0]);
	texture->height = ft_atoi(tmp[1]);
	texture->colors_num = ft_atoi(tmp[2]);
	texture->char_per_pixel = ft_atoi(tmp[3]);
	free_matrix(tmp);
}

void	parse_color_table(t_data *data, t_texture *texture, int fd)
{
	char	*line;
	char	*tmp;
	int		i;

	texture->color_table = malloc(sizeof(t_color_table_entry)
			* texture->colors_num);
	if (!texture->color_table)
		handle_error(data, ENOMEM, "Failed to allocate memory.");
	i = 0;
	while (i < texture->colors_num)
	{
		line = get_next_line(fd);
		tmp = line + 1;
		texture->color_table[i].symbol = ft_substr(tmp, 0,
				texture->char_per_pixel);
		texture->color_table[i].color = ft_atoi_hex(tmp
				+ texture->char_per_pixel);
		free(line);
		i++;
	}
}

void	parse_color_matrix(t_data *data, t_texture *texture, int fd)
{
	char	*line;
	int		i;

	texture->color_matrix = ft_calloc(sizeof(unsigned int *), texture->height
			+ 1);
	if (!texture->color_matrix)
		handle_error(data, ENOMEM, "Failed to allocate memory.");
	i = 0;
	while (i < texture->height)
	{
		line = get_next_line(fd);
		texture->color_matrix[i] = get_color_row(data, texture, line);
		free(line);
		i++;
	}
}
