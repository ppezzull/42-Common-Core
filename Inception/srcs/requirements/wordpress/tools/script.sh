#!/bin/bash

# Function to check MySQL connection
check_mysql_connection() {
    mysqladmin ping -h"$WORDPRESS_DB_HOST" -u"$WORDPRESS_DB_USER" -p"$WORDPRESS_DB_PASSWORD" > /dev/null 2>&1
}

# Wait for MySQL to be ready
echo "Waiting for MySQL to be ready..."
max_tries=30
counter=0

while ! check_mysql_connection; do
    counter=$((counter+1))
    if [ $counter -gt $max_tries ]; then
        echo "Failed to connect to MySQL after $max_tries attempts. Exiting..."
        exit 1
    fi
    echo "Attempt $counter/$max_tries: Waiting for MySQL to be ready..."
    sleep 5
done

echo "MySQL is ready! Proceeding with WordPress setup..."

# Check if wp-config.php exists
if [ ! -f /var/www/html/wp-config.php ]; then
    echo "Creating wp-config.php..."
    # Create wp-config.php file
    cat > /var/www/html/wp-config.php << EOF
<?php
define('DB_NAME', '${WORDPRESS_DB_NAME}');
define('DB_USER', '${WORDPRESS_DB_USER}');
define('DB_PASSWORD', '${WORDPRESS_DB_PASSWORD}');
define('DB_HOST', '${WORDPRESS_DB_HOST}');
define('DB_CHARSET', 'utf8');
define('DB_COLLATE', '');

\$table_prefix = 'wp_';

define('AUTH_KEY',         'put your unique phrase here');
define('SECURE_AUTH_KEY',  'put your unique phrase here');
define('LOGGED_IN_KEY',    'put your unique phrase here');
define('NONCE_KEY',        'put your unique phrase here');
define('AUTH_SALT',        'put your unique phrase here');
define('SECURE_AUTH_SALT', 'put your unique phrase here');
define('LOGGED_IN_SALT',   'put your unique phrase here');
define('NONCE_SALT',       'put your unique phrase here');

define('WP_DEBUG', false);

if ( ! defined('ABSPATH') ) {
    define('ABSPATH', __DIR__ . '/');
}

require_once ABSPATH . 'wp-settings.php';
EOF

    echo "Installing WP CLI..."
    # Install WP CLI
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp

    echo "Installing WordPress..."
    # Install WordPress
    cd /var/www/html
    wp core install --url=${DOMAIN_NAME} --title="WordPress Site" \
        --admin_user=${WP_ADMIN_USER} \
        --admin_password=${WP_ADMIN_PASSWORD} \
        --admin_email=${WP_ADMIN_EMAIL} \
        --allow-root
    
    # Create a regular user (non-admin)
    wp user create ${WP_USER} ${WP_USER_EMAIL} \
        --user_pass=${WP_USER_PASSWORD} \
        --role=author \
        --allow-root
    
    echo "WordPress installation completed!"
fi

echo "Starting PHP-FPM..."
# Ensure PHP-FPM starts properly
mkdir -p /run/php
chown www-data:www-data /run/php

# Start PHP-FPM and wait for it to be ready
php-fpm7.4 -F -R &
PHP_FPM_PID=$!

# Wait for PHP-FPM to be ready
echo "Waiting for PHP-FPM to be ready..."
while ! nc -z localhost 9000; do
    echo "PHP-FPM not ready yet..."
    sleep 1
done

echo "PHP-FPM is ready!"
wait $PHP_FPM_PID
