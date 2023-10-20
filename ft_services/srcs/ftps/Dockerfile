FROM alpine:3.12.3

# COPY ./srcs .
ADD srcs/lauch.sh .
ADD srcs/vsftpd.conf .

RUN apk update \
&& apk upgrade \
&& apk add vim  zsh openrc openssl


RUN	openssl req -x509 -nodes -subj '/CN=localhost' -days 365 -newkey rsa:4096 \
	-keyout /etc/ssl/private/vsftpd.key.pem -out /etc/ssl/certs/vsftpd.cert.pem
# RUN ssh-keygen -A


RUN apk add vsftpd \
&& rm /etc/vsftpd/vsftpd.conf \
&& mv vsftpd.conf /etc/vsftpd \
&& mkdir /srv/ftp \
&& chown nobody:nogroup /srv/ftp \
&& echo "anon" | tee /srv/ftp/anon.txt \
&& rc-update add vsftpd

EXPOSE 21 10080

CMD sh lauch.sh