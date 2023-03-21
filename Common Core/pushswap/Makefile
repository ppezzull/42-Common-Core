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

PUSH_NAME = push_swap

FLAGS = -Wall -Wextra -Werror
INC = -Iincludes/ -I$(LIB_DIR)/includes

PUSH_SRC_NAME = main.c swap.c push_swap.c print_program.c \
				push.c rotate.c rrotate.c utils.c \
				sort_utils.c stack_utils.c radix_sort.c \

PUSH_OBJ_NAME = $(PUSH_SRC_NAME:.c=.o)
PUSH_OBJ = $(addprefix $(OBJ_DIR),$(PUSH_OBJ_NAME))

LIB_DIR = libft/
SRC_DIR = srcs/
OBJ_DIR = objs/

all: $(PUSH_NAME)

$(PUSH_NAME): $(PUSH_OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(PUSH_NAME) $(PUSH_OBJ) -L $(LIB_DIR) -lft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -o $@ -c $< $(INC)

clean:
	@make -C $(LIB_DIR) clean  --silent
	@rm -f $(PUSH_OBJ)

fclean: clean
	@make -C $(LIB_DIR) fclean  --silent
	@rm -f $(PUSH_NAME)

re: fclean all

.PHONY: all clean fclean re
