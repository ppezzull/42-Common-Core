# Use Debian Bullseye as the base image for stability
FROM debian:bullseye

# Install MariaDB server and clean up package cache to reduce image size
RUN apt-get update && apt-get install -y \
    mariadb-server \
    && rm -rf /var/lib/apt/lists/*

# Create MySQL socket directory and set permissions
RUN mkdir -p /var/run/mysqld \
    && chown -R mysql:mysql /var/run/mysqld \
    && chmod 777 /var/run/mysqld

# Copy custom MariaDB configuration and initialization script
# - 50-server.cnf: Custom server configuration
# - script.sh: Database initialization script
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY tools/script.sh /usr/local/bin/

# Make the initialization script executable
RUN chmod +x /usr/local/bin/script.sh

# Expose the default MySQL/MariaDB port
EXPOSE 3306

# Run the initialization script and start MariaDB server
ENTRYPOINT ["/usr/local/bin/script.sh"]
CMD ["mysqld", "--user=mysql"]
