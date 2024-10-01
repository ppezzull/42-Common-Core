# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 04:39:21 by ppezzull          #+#    #+#              #
#    Updated: 2024/08/06 04:39:24 by ppezzull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)

EXEC = account

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean

