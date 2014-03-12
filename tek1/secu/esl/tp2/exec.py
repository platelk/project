#My script python

#include
from sys import *
from os import *


system("gcc -shared " + argv[1] + ".c -o " + argv[1] + ".so")
print("----ok ---")
system("LD_PRELOAD='`pwd`/" + argv[1] + ".so'" + argv[2])
