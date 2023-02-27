# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pietro <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 16:34:31 by pietro            #+#    #+#              #
#    Updated: 2023/02/17 16:34:34 by pietro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c

CC			= 	gcc
RM			= 	rm -f
FLAGS 		= 	-Wall -Wextra -Werror -I ./includes

OBJ_NAME 	= 	$(SRCS:.c=.o)
OBJ 		= 	$(addprefix $(OBJ_DIR),$(OBJ_NAME))
SRC_DIR 	= 	srcs/
OBJ_DIR 	= 	objs/

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAGS) -o $@ -c $< $(INC)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re