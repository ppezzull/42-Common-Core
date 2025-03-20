#!/bin/bash

# Wait for WordPress to be ready
until curl -s http://wordpress:9000 > /dev/null; do
    echo "Waiting for WordPress to be ready..."
    sleep 5
done

# Start Nginx
exec "$@"
