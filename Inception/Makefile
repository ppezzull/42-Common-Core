# Inception Project Makefile
# This project creates a complete WordPress setup using Docker containers
# The infrastructure consists of:
# - NGINX (web server with SSL)
# - WordPress (PHP-FPM)
# - MariaDB (database)

# Declare phony targets (targets that don't create files)
.PHONY: all setup build stop start restart clean fclean re

# Project name used for Docker resources
NAME = inception
COMPOSE_FILE = srcs/docker-compose.yml
DATA_PATH = /home/$(USER)/data

# Colors for pretty printing
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# Default target: builds and starts all containers
all: setup build

# Create necessary directories and setup environment
setup:
	@printf "$(GREEN)Creating data directories...$(RESET)\n"
	@sudo mkdir -p $(DATA_PATH)/wordpress
	@sudo mkdir -p $(DATA_PATH)/mariadb
	@sudo chmod 777 $(DATA_PATH)/wordpress
	@sudo chmod 777 $(DATA_PATH)/mariadb
	@printf "$(GREEN)Setting up hosts file...$(RESET)\n"
	@if ! grep -q "$(DOMAIN_NAME)" /etc/hosts; then \
		sudo sh -c 'echo "127.0.0.1 $(DOMAIN_NAME)" >> /etc/hosts'; \
	fi

# Builds all Docker images defined in docker-compose.yml
# - NGINX image with SSL configuration
# - WordPress image with PHP-FPM
# - MariaDB image with custom configuration
build:
	@printf "$(GREEN)Building and starting containers...$(RESET)\n"
	@docker compose -f $(COMPOSE_FILE) up --build -d

# Stops all containers
stop:
	@printf "$(RED)Stopping containers...$(RESET)\n"
	@docker compose -f $(COMPOSE_FILE) stop

# Starts all containers in detached mode (-d flag)
# This will:
# - Start NGINX listening on port 443 (HTTPS)
# - Start WordPress with PHP-FPM on port 9000
# - Start MariaDB on port 3306 (internal network only)
start:
	@printf "$(GREEN)Starting containers...$(RESET)\n"
	@docker compose -f $(COMPOSE_FILE) start

# Restart containers
restart:
	@printf "$(GREEN)Restarting containers...$(RESET)\n"
	@docker compose -f $(COMPOSE_FILE) restart

# Stops and removes all containers
# Containers will be stopped gracefully
clean:
	@printf "$(RED)Cleaning up containers and volumes...$(RESET)\n"
	@docker compose -f $(COMPOSE_FILE) down -v
	@sudo rm -rf $(DATA_PATH)

# Complete cleanup of all Docker resources
# Removes:
# - All containers
# - All images
# - All volumes (database data)
# - All networks
fclean: clean
	@printf "$(RED)Deep cleaning Docker resources...$(RESET)\n"
	@docker system prune -af

# Complete rebuild of the project
# Removes everything and starts fresh
re: fclean all
