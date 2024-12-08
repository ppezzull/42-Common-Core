/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rilliano <rilliano@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 03:01:02 by ppezzull          #+#    #+#             */
/*   Updated: 2024/12/03 10:26:46 by rilliano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_color_table_entry
{
	char				*symbol;
	unsigned int		color;
}						t_color_table_entry;

typedef struct s_texture
{
	char				*path;
	int					width;
	int					height;
	int					colors_num;
	int					char_per_pixel;
	t_color_table_entry	*color_table;
	unsigned int		**color_matrix;
}						t_texture;

typedef struct s_player
{
	double				x;
	double				y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				speed;
	double				rot_speed;
}						t_player;

typedef struct s_map
{
	char				**map;
	int					width;
	int					height;
}						t_map;

typedef struct s_minimap
{
	int					size;
	int					x_center;
	int					y_center;
	int					radius;
	int					wall_color;
	int					background_color;
	int					player_color;
}						t_minimap;

typedef struct s_raycast
{
	double				camera_x;
	double				ray_x;
	double				ray_y;
	int					map_x;
	int					map_y;
	double				delta_x;
	double				delta_y;
	double				side_x;
	double				side_y;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	double				wall_dist;
	int					line_h;
	int					draw_start;
	int					draw_end;
	double				wall_x;
	int					tex_x;
	double				step;
	double				tex_pos;
	int					tex_y;
	t_texture			*texture;
	unsigned int		color;
}						t_raycast;

typedef struct s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img;
	int					*img_addr;
	int					img_width;
	int					img_height;
	int					bpp;
	// bits per pixel (number of bits used to store one pixel color)
	int					size_l;
	// size line (number of bytes used to store one line of the image in memory)
	int					endian;
}						t_mlx;

typedef struct s_data
{
	t_mlx				mlx;
	t_map				map;
	t_player			player;
	char				pov;
	t_texture			north_texture;
	t_texture			south_texture;
	t_texture			west_texture;
	t_texture			east_texture;
	int					floor_color;
	int					ceiling_color;
}						t_data;

void					print_controls(void);

// main and init
int						main(int argc, char **argv);
void					init_data(t_data *data);
void					init_mlx(t_data *data);
void					init_textures(t_data *data);
void					listen_for_input(t_data *data);
int						render(t_data *data);
int						set_image(t_data *data);

// parser
int						parse_args(t_data *data, char **av);
int						parse_file(t_data *data, int fd);
char					*parse_elements_before_map(t_data *data, int fd);
int						save_texture_path(t_data *data, char *line);
int						parse_color(t_data *data, char *line, char c);
int						parse_map(t_data *data, char *line, int fd);
int						parse_map_line(t_data *data, char *line);
int						update_player_position(t_data *data);
void					set_point_of_view(t_data *data);
void					set_horizontal_pov(t_data *data);
void					set_vertical_pov(t_data *data);

// parse texture files
int						parse_textures(t_data *data);
int						parse_texture_data(t_data *data, t_texture *texture);
void					parse_texture_info(char *line, t_texture *texture,
							t_data *data);
void					parse_color_table(t_data *data, t_texture *texture,
							int fd);
void					parse_color_matrix(t_data *data, t_texture *texture,
							int fd);
unsigned int			*get_color_row(t_data *data, t_texture *texture,
							char *line);
unsigned int			get_color_by_symbol(t_texture *texture, char *symbol);

// format colors
int						get_color_from_rgb_str(char *str);
unsigned int			get_color_from_rgb_array(char **rgb);
unsigned int			ft_atoi_hex(char *str);
int						hex_char_to_int(char c);

// check data
int						check_elements(t_data *data);
int						check_textures(t_data *data);
int						check_colors(t_data *data);
int						check_texture_format(char *format);
int						is_texture(char *line);
int						check_file_path(t_data *data, char *path);
int						check_map(t_data *data);
int						check_map_characters(t_map *map);
int						check_map_borders(t_map *map);

// raycasting
void					render_cub(t_data *data);
void					fill_ceiling_and_floor(t_data *data, int w, int h);
void					render_wall_columns(t_data *data, int w, int h);
void					init_raycast(t_raycast *raycast, t_data *data, int x,
							int w);
void					calculate_step_and_side(t_raycast *raycast,
							t_data *data);
void					perform_dda(t_raycast *raycast, t_data *data);
void					calculate_wall_params(t_raycast *raycast, t_data *data,
							int h);
void					calculate_texture_params(t_data *data,
							t_raycast *raycast, int h);
void					render_column(t_data *data, t_raycast *raycast, int w,
							int x);

// key actions
int						cub_exit(t_data *data);
int						resize_window(t_data *data, XEvent *event);
int						key_press(int keycode, t_data *data);
void					move_player(t_data *data, char dir);
void					rotate_player(t_data *data, int dir);
void					calculate_new_position(t_data *data, char dir,
							double *new_x, double *new_y);

// utils
char					*line_start(char *line);
char					**ft_strtrim_split_args(char **strs, char *set);
int						ft_isdigit_split_args(char **strs);
int						get_row_len(char *str);

// free data
void					cub_free(t_data *data);
void					free_texture(t_texture *texture);
void					free_matrix(char **matrix);

// error handling
int						handle_error(t_data *data, int err, char *msg);
int						err_msg(char *msg, int err);

// -------------------------------- bonus --------------------------------
int						render_bonus(t_data *data);

// draw map
void					draw_map(t_data *data);
void					init_minimap(t_data *data, t_minimap *minimap);
void					draw_player(t_data *data, t_minimap *minimap);
void					draw_square(t_data *data, int x, int y,
							t_minimap *minimap);
void					draw_map_background(t_data *data, t_minimap *minimap);

#endif
