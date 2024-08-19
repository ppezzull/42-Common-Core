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

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Source files and object files
SRC = HumanA.cpp HumanB.cpp main.cpp Weapon.cpp 
OBJ = $(SRC:.cpp=.o)

# Executable name
EXEC = combat

# Default target
all: $(EXEC)

# Link the executable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files and executable
clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(EXEC)

# Phony targets
.PHONY: all clean

