/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:11:52 by ppezzull          #+#    #+#             */
/*   Updated: 2023/09/22 23:11:55 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	read_height(char *file_name)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		error("This file doesn't exist");
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (height == 0)
		error("Empty fdf file :-(");
	return (height - 1);
}

void	allocate_line(int fd, t_point **matrix, int y)
{
	char	*line;
	char	**nbr_lst;
	int		i;
	int		n_words;

	line = get_next_line(fd);
	nbr_lst = ft_split(line, ' ');
	n_words = -1;
	while (nbr_lst[n_words++ + 1])
		;
	matrix[y] = (t_point *)malloc(sizeof(t_point) * (n_words));
	i = -1;
	while (nbr_lst[i++ + 1])
	{
		matrix[y][i].x = i;
		matrix[y][i].y = y;
		read_point(nbr_lst[i], &matrix[y][i]);
		if (!nbr_lst[i + 1])
			matrix[y][i].is_last = 1;
		else
			matrix[y][i].is_last = 0;
		free(nbr_lst[i]);
	}
	free(line);
	free(nbr_lst);
}

t_point	**read_fdf(char *file_name)
{
	t_point	**matrix;
	char	*last_line;
	int		height;
	int		fd;
	int		i;

	height = read_height(file_name);
	fd = open(file_name, O_RDONLY, 0);
	matrix = (t_point **)malloc(sizeof(t_point *) * (height + 2));
	i = -1;
	while (i++ < height)
		allocate_line(fd, matrix, i);
	matrix[i] = NULL;
	last_line = get_next_line(fd);
	free(last_line);
	close(fd);
	return (matrix);
}
