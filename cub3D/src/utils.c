/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <rilliano@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 03:00:43 by ppezzull          #+#    #+#             */
/*   Updated: 2024/11/30 21:12:34 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*line_start(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	return (line + i);
}

int	is_texture(char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
		return (1);
	return (0);
}

int	get_row_len(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (i == 0)
		return (0);
	while (str[i] == ' ' || str[i] == '\n')
		i--;
	return (i + 1);
}

void	calculate_new_position(t_data *data, char dir, double *new_x,
		double *new_y)
{
	double	move_step;

	*new_x = data->player.x;
	*new_y = data->player.y;
	move_step = data->player.speed;
	if (dir == 'W' || dir == 'A')
		move_step *= 1;
	else if (dir == 'S' || dir == 'D')
		move_step *= -1;
	if (dir == 'W' || dir == 'S')
	{
		*new_x += data->player.dir_x * move_step;
		*new_y += data->player.dir_y * move_step;
	}
	else if (dir == 'A' || dir == 'D')
	{
		*new_x += data->player.dir_y * move_step;
		*new_y -= data->player.dir_x * move_step;
	}
}
