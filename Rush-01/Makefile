CC=gcc
CFILES=$(shell find src -type f -name "*.c")
HEADERS_DIR=src/
CFLAGS=-Wall -Wextra -Werror -I $(HEADERS_DIR)
DEBUG_FLAGS=-Wall -Wextra -Werror
NAME=rush-01
OBJS=${CFILES:.c=.o}

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf src/*.o

debug:
	$(CC) $(DEBUG_FLAGS) -g debug/test.c

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean debug fclean re