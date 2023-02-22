# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 16:34:09 by ppezzull          #+#    #+#              #
#    Updated: 2023/02/20 16:34:12 by ppezzull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_SRC = client.c
SERVER_SRC = server.c

CLIENT_NAME = client
SERVER_NAME = server

LIBFT_DIR = libft/
LIBFT = libft/libft.a

CC = gcc
FLAGS = -Wall -Werror -Wextra

all:
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(CLIENT_SRC) $(LIBFT) -o $(CLIENT_NAME)
	$(CC) $(FLAGS) $(SERVER_SRC) $(LIBFT) -o $(SERVER_NAME)

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME) $(LIBFT)
 
re:		all clean


