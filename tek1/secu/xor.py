#!/usr/bin/python2.7

# -*-coding:Latin-1 -*

from sys import *
from getopt import *
from os import *

i = 0
chaine = ""
while i < len(argv[1]):
    stdout.write (chr(ord(argv[1][i]) ^ 85))
    i += 1

print chaine
