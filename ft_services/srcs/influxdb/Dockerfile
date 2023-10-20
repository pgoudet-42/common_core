FROM alpine:3.12.3

COPY ./srcs .

RUN apk update
RUN apk add openrc vim zsh influxdb

RUN mkdir /etc/influxdb \
&& chown -R influxdb:influxdb /etc/influxdb/ \
&& rm /etc/influxdb.conf \
&& mv influxdb.conf /etc/influxdb/

CMD sh lauch.sh