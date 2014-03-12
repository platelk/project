#!/bin/sh
##
## gen.sh
##
## quentin leffray
## Thu Dec  8 2011


## Cree les repertoires de tests

mkdir -p ./map
mkdir -p ./special


## Cree les fichiers de tests

i=0
while (($i < 20))
do
    ./gen 10 10 1 > ./map/10x10_$i
    ((i += 1))
done
i=0
while (($i < 20))
do
    ./gen 25 25 2 > ./map/25x25_$i
    ((i += 1))
done
i=0
while (($i < 10))
do
    ./gen 100 100 10 > ./map/100x100_$i
    ((i += 1))
done
i=0
while (($i < 10))
do
    ./gen 250 250 10 > ./map/250x250_$i
    ((i += 1))
done
i=0
while (($i < 5))
do
    ./gen 1000 1000 100 > ./map/1000x1000_$i
    ((i += 1))
done
i=0
while (($i < 5))
do
    ./gen 2000 2000 300 > ./map/2000x2000_$i
    ((i += 1))
done

./gen 80 100000 13 > ./special/special_0
./gen 350 100000 3 > ./special/special_1
./gen 2000 50000 50 > ./special/special_2
