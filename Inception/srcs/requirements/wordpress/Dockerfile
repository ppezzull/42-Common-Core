FROM debian:bullseye

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
    && rm -rf /var/lib/apt/lists/*

# Download and install WordPress
RUN curl -O https://wordpress.org/latest.tar.gz \
    && tar -xzf latest.tar.gz \
    && rm latest.tar.gz \
    && mkdir -p /var/www/html \
    && mv wordpress/* /var/www/html/ \
    && rm -rf wordpress \
    && chown -R www-data:www-data /var/www/html

# Configure PHP-FPM
RUN sed -i 's/;clear_env = no/clear_env = no/' /etc/php/7.4/fpm/pool.d/www.conf

# Copy and make executable the WordPress setup script
COPY tools/script.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/script.sh

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/script.sh"]
CMD ["php-fpm7.4", "-F"]
