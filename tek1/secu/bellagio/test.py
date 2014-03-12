#!/usr/bin/python2.7                                                                 

# -*-coding:Latin-1 -*                                                               

##Mouli_push by platel_k  

from sys import *
from os import *
from subprocess import *

p = popen("echo " + "VmVyeSBzaW1wbGUgOykKUEFTUyA9IFVMVFJBU0lNUExF");
result = p.read()
i = 0
nb = 13

print result
print result[0] + "*"
print (result)
