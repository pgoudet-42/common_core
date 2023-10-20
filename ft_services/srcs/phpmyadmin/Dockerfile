FROM alpine:3.12.3

COPY ./srcs .

RUN apk update && apk add nginx && apk add wget ; \
        apk add lighttpd php7-common php7-iconv php7-json php7-gd php7-curl php7-xml php7-mysqli php7-imap \
        php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext \
        php7-ldap php7-ctype php7-dom php7-mbstring ; \
        apk add php7 php7-fpm php7-opcache ; \
        apk add php7-gd php7-mysqli php7-zlib php7-curl ; \
        apk add php-json ; \
        apk add php7-session ; \
		apk add openrc openssl openssh
RUN apk add mysql-client

RUN apk add lighttpd php7-common php7-session php7-iconv php7-json php7-gd php7-curl php7-xml \
php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt \
php7-gettext php7-ldap php7-ctype php7-dom

RUN mkdir /etc/nginx/ssl \
&& openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/services.pem -keyout /etc/nginx/ssl/services.key -subj "/C=FR/ST=Paris/L=Paris/O=42 School/OU=pilou/CN=localhost"

RUN mkdir ./run/nginx \
&& mkdir etc/nginx/conf

RUN mkdir -p var/run/nginx

RUN rm etc/nginx/nginx.conf \
&& mv nginx.conf etc/nginx \
&& adduser -D -g 'www' www \
&& mkdir /www \
&& rc-update add nginx default \
&& rc-update add php-fpm7 default \
&& reboot \
&& chown -R www:www /var/lib/nginx \
&& chown -R www:www /www \
&& chmod 777 /var/www


RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.zip \
&& unzip phpMyAdmin-5.0.4-all-languages.zip -d /var/www/ \
&& mv /var/www/phpMyAdmin-5.0.4-all-languages /var/www/phpmyadmin \
&& rm var/www/phpmyadmin/config.sample.inc.php \
&& mv config.inc.php /var/www/phpmyadmin/ \
&& chmod 777 /var/www/*

EXPOSE 5000

CMD sh lauch.sh