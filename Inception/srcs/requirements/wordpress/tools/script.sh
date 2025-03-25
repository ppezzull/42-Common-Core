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

define('AUTH_KEY',         'srt/ne.6jmHDf`3x`QI{6,]%AfvD^NWbjQiP.:SH|9T<h.KqPxZ#i+a||`nqg%uJ');
define('SECURE_AUTH_KEY',  '9L2sl0(R+l-T3z=RcWPe_$4-UyGWll$kE-;PA(~`NW<i)k}F.WfAg-d6U2!G&mAr');
define('LOGGED_IN_KEY',    'r7gGEyL6m]armVG+E.gi9$?j!^WsFa}] YrEHNEZrl-P#jIo$~jk[!+5W[?k?AJQ');
define('NONCE_KEY',        'Cij7kv`:;N$J5frdsXq<)+Zm=|mVCkwu*rv)ocGU!)Q|,j0&Xqnq4hxowZ=B%/~V');
define('AUTH_SALT',        '2&uV&JM)h:)8vcJFvzT7]DWL<F|a$W$SxjE>rMnY_ZA1|(i_$XtG;gpkME)]x]xi');
define('SECURE_AUTH_SALT', '{ro[tzYGJUXHy2-=Jrl}Uj,;m)(=t/rW[];eg%|6|A(}5g,)2G~TuZebNb+oB:*.');
define('LOGGED_IN_SALT',   'q-< E;6-zPWJ/:iSw|[%iMk5y3+gYCumzmmce1Yveb1V*h=Gt*Q7ixmQm5pe2G24');
define('NONCE_SALT',       '}ie}Rz 1`bg<~$l6}G/}ELPwdTx]xI-sKFX~-FO/-Y2<YM3eOuS ^*WB<Uora;r<');

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
# Ensure PHP-FPM directory exists
mkdir -p /run/php
chown www-data:www-data /run/php

# Execute the command passed to the script (PHP-FPM)
exec "$@"
