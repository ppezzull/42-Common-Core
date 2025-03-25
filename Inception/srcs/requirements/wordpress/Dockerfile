# Use Debian Bullseye as the base image for stability
FROM debian:bullseye

# Install required PHP extensions and utilities
# - php-fpm: FastCGI Process Manager for PHP
# - php-mysql: MySQL database support
# - php-gd: Image processing support
# - Additional PHP extensions for WordPress functionality
RUN apt-get update && apt-get install -y \
    php-fpm \
    php-mysql \
    php-gd \
    php-curl \
    php-mbstring \
    php-xml \
    php-xmlrpc \
    php-soap \
    php-intl \
    php-zip \
    curl \
    mariadb-client \
    netcat \
    sendmail \
    && rm -rf /var/lib/apt/lists/*

# Create and set proper permissions for web root
RUN mkdir -p /var/www/html && \
    chown -R www-data:www-data /var/www/html && \
    chmod -R 755 /var/www/html

# Download and install WordPress
WORKDIR /var/www/html
RUN curl -O https://wordpress.org/latest.tar.gz && \
    tar -xzf latest.tar.gz && \
    mv wordpress/* . && \
    rm -rf wordpress latest.tar.gz && \
    chown -R www-data:www-data . && \
    chmod -R 755 .

# Create required directories
RUN mkdir -p /var/run/mysqld \
    && chown -R www-data:www-data /var/run/mysqld \
    && chmod 777 /var/run/mysqld \
    && mkdir -p /run/php \
    && chown -R www-data:www-data /run/php \
    && chmod 777 /run/php

# Copy PHP-FPM configuration
COPY conf/www.conf /etc/php/7.4/fpm/pool.d/

# Set up WordPress initialization script
COPY tools/script.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/script.sh

# Expose port 9000 for PHP-FPM
EXPOSE 9000

# Run the initialization script and start PHP-FPM
ENTRYPOINT ["/usr/local/bin/script.sh"]
CMD ["php-fpm7.4", "-F"]
