#!/bin/bash

# Debug: Print environment variables
echo "Debug: Environment variables:"
echo "MYSQL_DATABASE: ${MYSQL_DATABASE}"
echo "MYSQL_USER: ${MYSQL_USER}"
echo "MYSQL_PASSWORD: ${MYSQL_PASSWORD}"
echo "MYSQL_ROOT_PASSWORD: ${MYSQL_ROOT_PASSWORD}"

# Start MySQL temporarily to check database
mysqld --user=mysql --skip-networking &
pid="$!"

# Wait for MySQL to start
for i in {30..0}; do
    if echo 'SELECT 1' | mysql --protocol=socket -uroot &> /dev/null; then
        break
    fi
    echo 'MySQL init process in progress...'
    sleep 1
done

if [ "$i" = 0 ]; then
    echo >&2 'MySQL init process failed.'
    exit 1
fi

# Check if database exists
if ! mysql --protocol=socket -uroot -e "USE ${MYSQL_DATABASE}" 2>/dev/null; then
    echo "Database ${MYSQL_DATABASE} does not exist. Creating..."
    
    # Create database and users
    mysql --protocol=socket -uroot << EOF
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
EOF

    # Verify database creation
    echo "Verifying database creation..."
    mysql --protocol=socket -uroot -p${MYSQL_ROOT_PASSWORD} -e "SHOW DATABASES;"
fi

# Stop MySQL
if ! kill -s TERM "$pid" || ! wait "$pid"; then
    echo >&2 'MySQL init process failed.'
    exit 1
fi

# Start MySQL normally
echo "Starting MySQL..."
exec mysqld --user=mysql
