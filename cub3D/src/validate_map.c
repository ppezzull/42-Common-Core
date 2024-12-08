/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <rilliano@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:57:03 by ppezzull          #+#    #+#             */
/*   Updated: 2024/11/30 21:12:52 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map(t_data *data)
{
	if (data->map.map == NULL)
		handle_error(data, ENOEXEC, "Invalid map.\tMap is missing.");
	if (data->map.width <= 2 || data->map.height <= 2)
		handle_error(data, ENOEXEC, "Invalid map.\tMap is too small.");
	if (data->pov == '0')
		handle_error(data, ENOEXEC,
			"Invalid map.\tPlayer position is missing.");
	if (check_map_characters(&data->map) == 1)
		handle_error(data, ENOEXEC, "Invalid map.\tInvalid character found.");
	if (check_map_borders(&data->map) == 1)
		handle_error(data, ENOEXEC, "Invalid map.\tMap is not closed.");
	return (0);
}

int	check_map_characters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map && map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0'
				&& map->map[i][j] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_horizontal_borders(t_map *map)
{
	int	i;
	int	last;

	i = 0;
	while (i < map->height)
	{
		last = ft_strlen(map->map[i]) - 1;
		if (*line_start(map->map[i]) != '1')
			return (1);
		if (map->map[i][last] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_vertical_borders(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (map->map[j] && (map->map[j][i] == ' '
			|| i >= (int)ft_strlen(map->map[j])))
			j++;
		if (map->map[j][i] != '1')
			return (1);
		while (map->map[j] && map->map[j][i])
			j++;
		j--;
		while (map->map[j] && (map->map[j][i] == ' '
			|| i >= (int)ft_strlen(map->map[j])))
			j--;
		if (map->map[j][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_map_borders(t_map *map)
{
	if (check_horizontal_borders(map) == 1)
		return (1);
	if (check_vertical_borders(map) == 1)
		return (1);
	return (0);
}
