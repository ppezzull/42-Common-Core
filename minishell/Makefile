# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ensteum <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 15:17:59 by ensteum           #+#    #+#              #
#    Updated: 2024/04/26 15:18:02 by ensteum          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINISHELL_NAME = minishell
#-Wextra
FLAGS = -Wall  -Werror
INC = -Iincludes/ -I$(LIB_DIR)/includes
LIBS = -lreadline

SRC_DIR = srcs/
LIB_DIR = libft/
OBJ_DIR = objs/

# Define the source files explicitly
MINISHELL_SRC := $(wildcard $(SRC_DIR)*.c)
MINISHELL_OBJ := $(MINISHELL_SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(MINISHELL_NAME)

$(MINISHELL_NAME): $(MINISHELL_OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(MINISHELL_NAME) $(MINISHELL_OBJ) -L $(LIB_DIR) -lft $(LIBS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) $(INC) -o $@ -c $<

format:
	@find includes srcs -name '*.c' -o -name '*.h' | xargs c_formatter_42

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIB_DIR) clean --silent

fclean: clean
	@rm -f $(MINISHELL_NAME)
	@make -C $(LIB_DIR) fclean --silent

re: fclean all

.PHONY: all format clean fclean re
