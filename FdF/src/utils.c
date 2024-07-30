/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:10:11 by ppezzull          #+#    #+#             */
/*   Updated: 2023/09/26 15:10:14 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_matrix(t_point **matrix)
{
	int	y;

	y = 0;
	while (matrix[y])
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
}

float	fmodule(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

int	get_max(int a, int b)
{
	int	result;

	if (a > b)
		result = a;
	else
		result = b;
	return (result);
}
