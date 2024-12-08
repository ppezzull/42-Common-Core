/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pov.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:49:38 by ppezzull          #+#    #+#             */
/*   Updated: 2024/11/30 15:49:40 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_point_of_view(t_data *data)
{
	if (data->pov == 'W' || data->pov == 'E')
		set_horizontal_pov(data);
	else if (data->pov == 'N' || data->pov == 'S')
		set_vertical_pov(data);
}

void	set_horizontal_pov(t_data *data)
{
	if (data->pov == 'W')
	{
		data->player.dir_x = -1.0;
		data->player.plane_y = -0.66;
	}
	else
	{
		data->player.dir_x = 1.0;
		data->player.plane_y = 0.66;
	}
	data->player.dir_y = 0.0;
	data->player.plane_x = 0.0;
}

void	set_vertical_pov(t_data *data)
{
	data->player.dir_x = 0.0;
	if (data->pov == 'N')
	{
		data->player.dir_y = -1.0;
		data->player.plane_x = 0.66;
	}
	else
	{
		data->player.dir_y = 1.0;
		data->player.plane_x = -0.66;
	}
	data->player.plane_y = 0.0;
}
