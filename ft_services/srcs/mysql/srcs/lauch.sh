#!/bin/sh

/etc/init.d/mariadb setup
service mariadb start

 mysql -u root -e "create user '${MYSQL_USER}'@'%' identified by '${MYSQL_PASSWORD}'"
# mysql -u root -e "create user 'root'@'%' identified by 'password'"
mysql -u root -e "create database wordpress"
mysql -u root -e "grant all privileges on *.* to '${MYSQL_USER}'@'%'"
#mysql -u root -e "grant all privileges on *.* to 'root'@'%'"
mysql -u root -e "flush privileges"
mysql -u root -e "exit"
service mariadb stop

sed -i "s|.*skip-networking.*|#skip-networking|g" /etc/my.cnf.d/mariadb-server.cnf
service mariadb start
mysqld --user=root
while true;
do
	if ! pgrep mysql >/dev/null 2>&1 ; then
		exit 1
	fi
	sleep 2
done