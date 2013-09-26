#!/usr/bin/python3.3
import sys

a = 1
b = 0
c = 0
i = 0
while i < int(sys.argv[1]):
    print (str(b) + " ", end='')
    c = b
    b = a
    a = a + c
    i += 1
print("\n End")