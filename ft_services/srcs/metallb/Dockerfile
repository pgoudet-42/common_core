FROM alpine:3.12.3

COPY ./srcs .

RUN apk update \
&& apk upgrade \
&& apk add vim nginx wget openssl openrc

RUN mkdir /etc/nginx/ssl \
&& openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/services.pem -keyout /etc/nginx/ssl/services.key -subj "/C=FR/ST=Paris/L=Paris/O=42 School/OU=pilou/CN=localhost"

RUN mkdir ./run/nginx \
&& mkdir etc/nginx/conf

RUN rm etc/nginx/nginx.conf \
&& mv nginx.conf etc/nginx \
&& adduser -D -g 'www' www \
&& mkdir /www \
&& rc-update add nginx default \
&& reboot \
&& cp /var/lib/nginx/html/index.html /www/ \
&& chown -R www:www /var/lib/nginx \
&& chown -R www:www /www \
&& chmod 777 /var/www


EXPOSE 80 443

CMD ["nginx", "-g", "daemon off;"]
