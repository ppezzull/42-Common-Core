# Use the official Debian Bullseye image as the base image
FROM debian:bullseye

# Update the package list and install necessary packages
RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    curl \
    netcat \
    && rm -rf /var/lib/apt/lists/*

# Generate a self-signed SSL certificate for secure connections
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx-selfsigned.key \
    -out /etc/ssl/certs/nginx-selfsigned.crt \
    -subj "/C=US/ST=State/L=City/O=Organization/CN=localhost"

# Copy the Nginx configuration file from the host to the container
COPY conf/default.conf /etc/nginx/conf.d/

# Copy a custom script to the container and make it executable
COPY tools/script.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/script.sh

# Expose port 443 for HTTPS traffic
EXPOSE 443

# Set the entry point to the custom script
ENTRYPOINT ["/usr/local/bin/script.sh"]

# Set the default command to run Nginx in the foreground
CMD ["nginx", "-g", "daemon off;"]
