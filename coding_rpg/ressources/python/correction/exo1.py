#!/usr/bin/python3.3

import sys

i = 0
try:
    if (len(sys.argv) > 1):
        while i <= 10:
            print("{} * {} = {}".format(i, sys.argv[1], i * int(sys.argv[1])))
            i += 1
except:
    print("Error")