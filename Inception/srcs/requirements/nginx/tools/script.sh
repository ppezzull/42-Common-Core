#!/bin/bash

# Wait for WordPress container to be ready
echo "Waiting for WordPress container..."
until nc -z wordpress 9000; do
    echo "Waiting for WordPress to be ready..."
    sleep 2
done

echo "WordPress is ready! Starting NGINX..."

# Start Nginx
exec "$@"
