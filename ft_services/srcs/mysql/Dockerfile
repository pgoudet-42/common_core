FROM alpine:3.12.3

COPY ./srcs .

RUN apk update
RUN apk add openrc
RUN apk add mariadb mariadb-client
RUN rc-status
RUN touch /run/openrc/softlevel
RUN	chmod 777 lauch.sh
EXPOSE 3306
RUN echo TTTTTTTTTEEEEEEEESSSSSSSTTTTTTTT
CMD sh lauch.sh
