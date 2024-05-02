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

FLAGS = -Wall -Wextra -Werror
INC = -Iincludes/ -I$(LIB_DIR)/includes
LIBS = -lreadline

SRC_DIR = srcs/
EXECUTOR_DIR = $(SRC_DIR)executor/
PARSER_DIR = $(SRC_DIR)parser/
SIGNAL_DIR = $(SRC_DIR)signal/

# Define the source files using wildcard
MINISHELL_SRC := $(wildcard $(SRC_DIR)*.c)
EXECUTOR_SRC := $(wildcard $(EXECUTOR_DIR)*.c)
PARSER_SRC := $(wildcard $(PARSER_DIR)*.c)
SIGNAL_SRC := $(wildcard $(SIGNAL_DIR)*.c)

# Define object files
MINISHELL_OBJ := $(MINISHELL_SRC:.c=.o)
EXECUTOR_OBJ := $(EXECUTOR_SRC:.c=.o)
PARSER_OBJ := $(PARSER_SRC:.c=.o)
SIGNAL_OBJ := $(SIGNAL_SRC:.c=.o)

OBJ_DIR = objs/

all: $(MINISHELL_NAME)

$(MINISHELL_NAME): $(MINISHELL_OBJ) $(EXECUTOR_OBJ) $(PARSER_OBJ) $(SIGNAL_OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $@ $^ -L $(LIB_DIR) -lft $(LIBS)

%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) $(INC) -o $(OBJ_DIR)$@ -c $<

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
