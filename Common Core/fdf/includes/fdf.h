/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:53:18 by ppezzull          #+#    #+#             */
/*   Updated: 2023/09/22 22:53:19 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include <math.h>
# include "stdio.h"
# include <fcntl.h>


# ifndef FDF
    # define FDF

# define KEY_ESC    65307
# define KEY_LEFT	65361
# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364

typedef struct s_point
{
	float		x;
	float		y;
	int			z;
	int			is_last;

	int			color;
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
	double		angle;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_point;

float		fmodule(float i);

int 		read_height(char *file_name);
int        	handle_keys(int key, t_point **matrix);

void        error(char *message);
void    	draw_fdf(t_point **matrix);
void 		free_matrix(t_point **matrix);
void		zoom(t_point *a, t_point *b, t_point *param);
void		isometric(t_point *point, double angle);

t_point     **read_fdf(char *file_name);

#endif