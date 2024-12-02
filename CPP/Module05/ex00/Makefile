# Makefile for Exercise 00

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

NAME := bureaucrat
SRC := main.cpp Bureaucrat.cpp
OBJ := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
