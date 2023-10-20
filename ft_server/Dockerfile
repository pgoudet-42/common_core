FROM debian:buster

COPY ./srcs/ .

RUN apt-get update \
&& apt-get upgrade \
&& apt-get install -y vim mariadb-server nginx  wget php-json php-mbstring unzip zsh 

RUN apt-get install -y php-fpm php-mysql php-mbstring php-zip php-gd php-xml php-pear php-gettext php-cgi openssl\
&& rm -f /etc/php/7.3/fpm/php.ini \
&& mv /php.ini /etc/php/7.3/fpm

RUN mkdir /etc/nginx/ssl \
&& openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/localhost.pem -keyout /etc/nginx/ssl/localhost.key -subj "/C=FR/ST=Paris/L=Paris/O=42 School/OU=pilou/CN=localhost"

RUN service mysql start \
&& echo "CREATE DATABASE wordpress;" | mysql -u root \
&& echo "CREATE USER 'pl'@'localhost' IDENTIFIED BY 'test';" | mysql -u root \
&& echo "GRANT ALL PRIVILEGES ON * . * TO 'pl'@'localhost';" | mysql -u root \
&& echo "FLUSH PRIVILEGES;" | mysql -u root

RUN wget https://fr.wordpress.org/wordpress-5.6-fr_FR.zip \
&& unzip wordpress-5.6-fr_FR.zip -d var/www/html \
&& mv wp-config.php /var/www/html/wordpress/ 

RUN  wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.zip \
&& unzip phpMyAdmin-5.0.4-all-languages.zip -d /var/www/html/ \
&& mv /var/www/html/phpMyAdmin-5.0.4-all-languages /var/www/html/phpmyadmin \
&& mv config.inc.php /var/www/html/phpmyadmin

RUN rm -f *.zip

EXPOSE 80 443
CMD sh run.sh