FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    mariadb-server \
    && rm -rf /var/lib/apt/lists/*

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY tools/script.sh /docker-entrypoint-initdb.d/

RUN chmod +x /docker-entrypoint-initdb.d/script.sh

EXPOSE 3306

ENTRYPOINT ["/docker-entrypoint-initdb.d/script.sh"]
CMD ["mysqld"]
