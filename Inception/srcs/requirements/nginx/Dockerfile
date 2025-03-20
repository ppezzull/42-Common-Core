FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    curl \
    && rm -rf /var/lib/apt/lists/*

# Generate SSL certificate
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx-selfsigned.key \
    -out /etc/ssl/certs/nginx-selfsigned.crt \
    -subj "/C=US/ST=State/L=City/O=Organization/CN=localhost"

COPY conf/default.conf /etc/nginx/conf.d/
COPY tools/script.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/script.sh

EXPOSE 443

ENTRYPOINT ["/usr/local/bin/script.sh"]
CMD ["nginx", "-g", "daemon off;"]
