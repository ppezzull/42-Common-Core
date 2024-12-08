S = src/
O = obj/
I = ./
LIBFT_PATH = ./libft/
MLX_PATH = ./minilibx-linux/
LIBFT = $(LIBFT_PATH)libft.a
MLX = $(MLX_PATH)libmlx.a
LIB = -L$(LIBFT_PATH) -L$(MLX_PATH) -lft -lmlx -lXext -lX11 -lm
INC = -I$I -I$(LIBFT_PATH) -I$(MLX_PATH)

SRC = \
	$Smain.c \
	$Sinit_data.c \
	$Sutils.c \
	$Skey_actions.c \
	$Sparse_args.c \
	$Sparse_map.c \
	$Sparse_texture.c \
	$Scolor.c \
	$Scolor_utils.c \
	$Sset_pov.c \
	$Srender_cub.c \
	$Srender_utils.c \
	$Svalidate_data.c \
	$Svalidate_map.c \
	$Serror_handling.c \
	$Sfree.c

BSRC = \
	$Smain_bonus.c \
	$Sinit_data.c \
	$Sutils.c \
	$Skey_actions.c \
	$Sparse_args.c \
	$Sparse_map.c \
	$Sparse_texture.c \
	$Scolor.c \
	$Scolor_utils.c \
	$Sset_pov.c \
	$Srender_cub.c \
	$Srender_utils.c \
	$Svalidate_data.c \
	$Svalidate_map.c \
	$Serror_handling.c \
	$Sfree.c \
	$Sdraw_map.c

OBJ = $(SRC:$S%.c=$O%.o)
BOBJ = $(BSRC:$S%.c=$O%.o)

NAME = cub3D
NAME_B = cub3D_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
RMDIR = rmdir

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(MLX):
	# Ensure MinilibX is extracted before building
	echo "Extracting MinilibX..."; \
	tar xf minilibx-linux.tgz -C .; \
	make -C $(MLX_PATH) all

$O:
	mkdir -p $@

$(OBJ): | $O

$(BOBJ): | $O

$O%.o: $S%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIB) $(INC)

bonus:	$(NAME_B)

$(NAME_B): $(MLX) $(LIBFT) $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -o $@ $(LIB) $(INC)

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(MLX_PATH)
	$(RM) $(LIBFT)
	$(RM) $(NAME) $(NAME_B)

re: fclean all

format:
	@c_formatter_42 $(S)*.c cub3d.h

.PHONY: all bonus clean fclean re extract format
