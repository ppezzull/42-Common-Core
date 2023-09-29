# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pietro <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 16:43:20 by pietro            #+#    #+#              #
#    Updated: 2023/02/21 16:43:26 by pietro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isdigit.c ft_memset.c ft_strjoin.c ft_strtrim.c ft_isprint.c \
ft_putchar_fd.c ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c ft_putendl_fd.c \
ft_strlcpy.c ft_tolower.c ft_bzero.c ft_putnbr_fd.c ft_strlen.c ft_pow.c \
ft_toupper.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strmapi.c ft_isalnum.c \
ft_memcmp.c ft_split.c ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c\
ft_strnstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_striteri.c \
ft_lstadd_back.c ft_lstadd_front.c ft_lstdelone.c ft_lstclear.c ft_isnumeric.c\
ft_lstiter.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstmap.c ft_isspace.c \
ft_printf.c ft_useful_scripts.c ft_print_utils.c ft_hex.c ft_putptr.c ft_print_int_lst.c\
get_next_line.c 

CC			= 	gcc
RM			= 	rm -f
FLAGS 		= 	-Wall -Wextra -Werror -I ./includes

OBJ_NAME 	= 	$(SRCS:.c=.o)
OBJ 		= 	$(addprefix $(OBJ_DIR),$(OBJ_NAME))
SRC_DIR 	= 	srcs/
OBJ_DIR 	= 	objs/

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -o $@ -c $< $(INC)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
