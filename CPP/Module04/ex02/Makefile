CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = AAnimal.cpp Brain.cpp Cat.cpp Dog.cpp main.cpp 
OBJS = $(SRCS:.cpp=.o)
NAME = animal_polymorphism

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
