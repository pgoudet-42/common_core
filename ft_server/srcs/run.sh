#!/bin/sh
if [ "$ai" != "off" ]
then
 	rm default2
else
	rm default
	mv default2 default
fi

chmod -R 755 /var/www/*
chown -R www-data:www-data /var/www/*
mv index.html /var/www/html
rm etc/nginx/sites-available/default
mv default etc/nginx/sites-available/default 
rm /etc/nginx/sites-enabled/default
cp etc/nginx/sites-available/default /etc/nginx/sites-enabled/
chown -R www-data:www-data etc/nginx/sites-available/default
service mysql start
mysql -u root < /var/www/html/phpmyadmin/sql/create_tables.sql
service php7.3-fpm start
nginx -g "daemon off;"