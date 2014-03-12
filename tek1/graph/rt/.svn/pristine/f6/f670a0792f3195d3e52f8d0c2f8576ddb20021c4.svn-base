#!/bin/bash
## remote_control.bash for remote in /home/guiho_r/tek1/rt/clustering
##
## Made by ronan guiho
## Login   <guiho_r@epitech.net>
##
## Started on  Fri Jun  1 13:25:35 2012 ronan guiho
##

# Ctrl+C
trap ctrl_c INT

function ctrl_c()
{
    echo "DELETE FROM server WHERE host=\"$ip:$port\"" > /tmp/query2.sql
    results=`mysql $name -h $host -u $user -pbcdmdas2 < /tmp/query2.sql`
    exit
}

# Configuration Argument Raytracer
type=$1
link_scene=$3
port=$2
wait=$5

os=`uname -r`
files="lol.txt"

if [[ $os == "2.6.35.13-92.fc14.x86_64" ]]
then
    nc="nc"
    ip=`ifconfig  wlan0| grep 'inet addr:'| grep -v '127.0.0.1' | cut -d: -f2 | awk '{ print $1}'`
else
    if [[ $os == "3.3.6-1-ARCH" ]]
    then
	nc="/usr/bin/nc.openbsd"
	ip=`ifconfig wlan0 | grep -E 'inet.[0-9]' | grep -v '127.0.0.1' | awk '{ print $2}'`
    else
	nc="nc"
	ip=`ifconfig  wlan0| grep 'inet addr:'| grep -v '127.0.0.1' | cut -d: -f2 | awk '{ print $1}'`
    fi
fi

if [[ $type == "--client" ]]
then
    port_rt=$3
else
    port_rt=$4
fi
# Configuration Database
host="88.191.133.132"
user="antiqe"
name="allum1"

# Configuration Color Message
green="\\033[1;32m"
normal="\\033[0;39m"
red="\\033[1;31m"

i=0

if [[ $type == "--server" ]]
then
    wget $link_scene -O tmp.xml
    echo "SELECT host FROM server" > /tmp/query.sql
    results=`mysql $name -h $host -u $user -pbcdmdas2 < /tmp/query.sql`
    ./raytracer --server -p $port_rt -w $wait tmp.xml &
    for row in $results
    do
	ip_client=`echo $row | cut -d':' -f1`
	port_client=`echo $row | cut -d':' -f2`
	echo $ip_client
	echo $port_client
	exec 5<> /dev/tcp/$ip_client/$port_client
	echo "URL $link_scene">&5
	echo "IP $ip">&5
	echo "PORT $port_rt">&5
    done
else
    if [[ $type == "--client" ]]
    then
	echo "INSERT INTO server VALUES('', '$ip:$port', '')" > /tmp/query1.sql
	mysql $name -h $host -u $user -pbcdmdas2 < /tmp/query1.sql
	while [ $i -lt 2 ]
	do
	    echo -n "Listen "
	    echo $port
	    echo -n "Port for rt : "
	    echo $port_rt
	    echo "Creation log file ..."

	    $nc -l $port > $files
	    url=`cat $files | grep URL | cut -d' ' -f2`
	    ip_recv=`cat $files | grep IP | cut -d' ' -f2`
	    port_recv=`cat $files | grep PORT | cut -d' ' -f2`

	    echo "Get scene ..."
	    wget $url -O tmp.xml
	    echo $ip_recv
	    echo "Calcul ..."
	    ./raytracer --client -i $ip_recv -p $port_rt tmp.xml -t 1
	    rm -f tmp.xml
	    port_rt=$(($port_rt + 1))
	done
    else
	echo "Usage: ./remote_control.bash --mode"
	echo "       --server port_listen scene port_rt wait_client(en seconde)"
	echo "       --client port_listen"
    fi
fi