/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 03:00:13 by ppezzull          #+#    #+#             */
/*   Updated: 2024/11/27 03:00:16 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_args(t_data *data, char **av)
{
	int		fd;
	char	*format;

	format = ft_strrchr(av[1], '.');
	if (!format || ft_strlen(format) != 4 || ft_strncmp(ft_strrchr(av[1], '.'),
			".cub", 4) != 0)
		handle_error(data, EINVAL,
			"Invalid file format. Only .cub files are accepted.");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		handle_error(data, errno, "Failed to open file.");
	parse_file(data, fd);
	close(fd);
	parse_textures(data);
	set_point_of_view(data);
	return (0);
}

int	parse_file(t_data *data, int fd)
{
	char	*line;

	line = parse_elements_before_map(data, fd);
	check_elements(data);
	if (line)
		parse_map(data, line, fd);
	check_map(data);
	return (0);
}

char	*parse_elements_before_map(t_data *data, int fd)
{
	char	*line;
	char	*start;

	line = get_next_line(fd);
	while (line)
	{
		start = line_start(line);
		if (ft_strncmp(start, "1", 1) == 0)
			return (line);
		if (is_texture(start))
			save_texture_path(data, start);
		else if (ft_strncmp(start, "F", 1) == 0 || ft_strncmp(start, "C",
				1) == 0)
			parse_color(data, start, *start);
		else if (*start != '\0' && *start != '\n')
			handle_error(data, ENOEXEC, "Invalid map.");
		free(line);
		line = get_next_line(fd);
	}
	return (NULL);
}

int	save_texture_path(t_data *data, char *line)
{
	char	*tmp;
	char	k;

	k = *line;
	tmp = ft_strtrim(line + 2, " \n\t\v\f\r");
	if (!tmp)
		handle_error(data, ENOMEM, "Failed to allocate memory.");
	if (k == 'N' && data->north_texture.path == NULL)
		data->north_texture.path = ft_strdup(tmp);
	else if (k == 'S' && data->south_texture.path == NULL)
		data->south_texture.path = ft_strdup(tmp);
	else if (k == 'W' && data->west_texture.path == NULL)
		data->west_texture.path = ft_strdup(tmp);
	else if (k == 'E' && data->east_texture.path == NULL)
		data->east_texture.path = ft_strdup(tmp);
	else
		handle_error(data, ENOEXEC,
			"Invalid texture.\tMultiple textures found.");
	free(tmp);
	return (0);
}

int	parse_color(t_data *data, char *line, char c)
{
	int	rgb;

	if (c == 'F' && data->floor_color != -1)
		handle_error(data, ENOEXEC,
			"Invalid color.\tMultiple floor colors found.");
	else if (c == 'C' && data->ceiling_color != -1)
		handle_error(data, ENOEXEC,
			"Invalid color.\tMultiple ceiling colors found.");
	rgb = get_color_from_rgb_str(line + 1);
	if (rgb == -1)
		handle_error(data, ENOEXEC, "Invalid color.");
	if (c == 'F')
		data->floor_color = rgb;
	else if (c == 'C')
		data->ceiling_color = rgb;
	return (0);
}
