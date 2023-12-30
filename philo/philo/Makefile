# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 16:24:08 by ppezzull          #+#    #+#              #
#    Updated: 2023/11/29 16:24:10 by ppezzull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

RED=\033[0;31m
GREEN=\033[0;32m
RESET=\033[0m

CC = gcc -g
 
CFLAGS = -Wall -Wextra -Werror -pthread -Iincludes
SRCS = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c,obj/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "${GREEN}Philosopher compiled${RESET}"

obj/%.o: src/%.c
	@mkdir -p obj
	@if [ ! -e obj/compiled.flag ]; then \
		echo -n "${GREEN}Compiling source files"; \
		for i in 1 2 3; do \
			echo -n "."; \
			sleep 0.5; \
		done; \
		echo "${RESET}"; \
		touch obj/compiled.flag; \
	fi
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf obj
	@rm -f obj/compiled.flag
	@echo "${RED}Object files cleaned${RESET}"

fclean: clean
	@rm -f $(NAME)
	@echo "${RED}Executable removed${RESET}"

re: fclean all

.PHONY: all clean fclean re