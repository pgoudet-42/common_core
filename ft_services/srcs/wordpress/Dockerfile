FROM alpine:3.12.3

COPY ./srcs .

RUN apk update && apk add nginx && apk add wget ; \
        apk add lighttpd php7-common php7-iconv php7-json php7-gd php7-curl php7-xml php7-mysqli \
        php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt \
        php7-gettext php7-ldap php7-ctype php7-dom php7-mbstring ; \
        apk add php7 php7-fpm php7-opcache ; \
        apk add php7-gd php7-mysqli php7-zlib php7-curl ; \
        apk add php-json ; \
        apk add php7-session ; \
		apk add openrc openssl openssh
RUN apk add mysql-client

RUN apk add lighttpd php7-common php7-session php7-iconv php7-json php7-gd php7-curl \
php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc \
php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom

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


RUN mkdir /run/nginx

RUN mkdir /etc/nginx/ssl \
&& openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/services.pem -keyout /etc/nginx/ssl/services.key -subj "/C=FR/ST=Paris/L=Paris/O=42 School/OU=pilou/CN=localhost"

RUN wget -q https://fr.wordpress.org/wordpress-5.6-fr_FR.tar.gz \
&& tar -xzvf wordpress-5.6-fr_FR.tar.gz \
&& rm wordpress-5.6-fr_FR.tar.gz

EXPOSE 5050

CMD sh lauch.sh