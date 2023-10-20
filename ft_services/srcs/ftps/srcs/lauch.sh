#!/bin/sh
# service vsftpd restart
# tail -f /var/log/vsftpd.log
adduser -D "moi" && echo "password" | chpasswd
chown -R user42:user42 /home/user42
touch /var/log/vsftpd.log
echo "moi" | tee -a /etc/vsftpd.userlist
service vsftpd restart
tail -f /var/log/vsftpd.log