.PHONY: up down build re clean fclean

NAME = inception

all: build up

build:
	docker-compose -f srcs/docker-compose.yml build

up:
	docker-compose -f srcs/docker-compose.yml up -d

down:
	docker-compose -f srcs/docker-compose.yml down

re: fclean all

clean:
	docker-compose -f srcs/docker-compose.yml down --rmi all

fclean: clean
	docker system prune -af --volumes
