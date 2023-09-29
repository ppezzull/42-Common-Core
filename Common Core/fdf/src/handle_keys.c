/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 00:19:42 by ppezzull          #+#    #+#             */
/*   Updated: 2023/09/23 00:19:47 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int    handle_keys(int key, t_point **matrix)
{
    t_point *param;
    
    param = &matrix[0][0];
    if (key == KEY_ESC)
    {
        mlx_destroy_window(param->mlx_ptr, param->win_ptr);
        mlx_destroy_display(param->mlx_ptr);
		free_matrix(matrix);
		exit(0);
    }
    return (0);
}
