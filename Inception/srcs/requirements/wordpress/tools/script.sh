#!/bin/bash

# Wait for database to be ready
sleep 10

# Check if wp-config.php exists
if [ ! -f /var/www/html/wp-config.php ]; then
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

    # Install WP CLI
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp

    # Wait until MySQL is ready
    until mysql -h${WORDPRESS_DB_HOST} -u${WORDPRESS_DB_USER} -p${WORDPRESS_DB_PASSWORD} -e "SELECT 1"; do
        echo "Waiting for MySQL to be ready..."
        sleep 5
    done

    # Install WordPress
    cd /var/www/html
    wp core install --url=localhost --title="WordPress Site" --admin_user=admin --admin_password=admin_password --admin_email=admin@example.com --allow-root
fi

# Start PHP-FPM
exec "$@"
