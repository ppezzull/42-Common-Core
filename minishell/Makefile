MINISHELL_NAME = minishell

FLAGS = -Wall -Wextra -Werror
INC = -Iincludes/ -I$(LIB_DIR)/includes

SRC_DIR = srcs/
LIB_DIR = libft/
OBJ_DIR = objs/

# Find all .c files recursively
MINISHELL_SRC := $(shell find $(SRC_DIR) -name '*.c')

# Generate object file names
MINISHELL_OBJ := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(MINISHELL_SRC))

all: $(MINISHELL_NAME)

$(MINISHELL_NAME): $(MINISHELL_OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(MINISHELL_NAME) $(MINISHELL_OBJ) -L $(LIB_DIR) -lft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -o $@ -c "$<" $(INC)

clean:
	@make -C $(LIB_DIR) clean --silent
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIB_DIR) fclean --silent
	@rm -f $(MINISHELL_NAME)

re: fclean all

.PHONY: all clean fclean re
