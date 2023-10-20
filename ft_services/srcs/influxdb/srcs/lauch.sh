service influxdb start

while true;
do
	if ! pgrep mysql >/dev/null 2>&1 ; then
		exit 1
	fi
	sleep 2
done