/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:14:06 by ppezzull          #+#    #+#             */
/*   Updated: 2023/10/11 14:14:09 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void fdf_put_string(t_point *param) {
    char *str[] = {
        "ppezzull FDF",
        "ESC     ->    quit program",
        "WASD    ->    move the projection around",
        "N / M   ->    change Z scale",
        "I       ->    isometric projection",
        "O       ->    top view",
        "P       ->    perspective view"
    };

    int line_height = 15;
    int line_number = 0;
    int num_lines = sizeof(str) / sizeof(str[0]);

    while (line_number < num_lines) {
        mlx_string_put(param->mlx_ptr, param->win_ptr, 10, line_height * line_number + 15, DARK_PURPLE, str[line_number]);
        line_number++;
    }
}
