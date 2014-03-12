#!/usr/bin/python2.7

# -*-coding:Latin-1 -*

from os import *
from sys import *
from subprocess import *
from commands import *
from getopt import *
from time import *

try:
    opts, args = getopt(argv[1:], "hct", ["help", "comp", "time"])
except GetoptError:
    print("Usage : ./mouli_bistro --option <expr> (<base> '<op>')")
    print("if <base> or '<op>' are not specified, The base decimal and operator normal will be used")
    sys.exit(2)

base = "0123456789"

ope = "()+-*/%"

if len(args) == 0:
        print("Usage : ./mouli_bistro --option <expr> <base> '<op>'")
        print("if <base> or '<op>' are not specified, The base decimal and operator normal will be used")
	exit(1)
if len(args) >= 2:
	base = args[1]
if len(args) >= 3:
	ope = args[2]

expr = str(args[0])
lenth = str(len(expr))

for o, a in opts:
    if o in ("-h", "--help"):
        print("Usage : ./mouli_bistro --option <expr> <base> '<op>'")
        print("if <base> or '<op>' are not specified, The base decimal and operator normal will be used")
    elif o in ("-c", "--comp"):
        p3 = Popen(["echo", expr], stdout=PIPE)
        p4 = Popen(["bc"], stdin=p3.stdout, stdout=PIPE)
        p3.stdout.close()
        output = p4.communicate()[0]
        print("Result BC : ")
        print(output)


p1 = Popen(["echo", expr], stdout=PIPE)
begin = time()
p2 = Popen(["./calc", base, ope, lenth], stdin=p1.stdout, stdout=PIPE)
p1.stdout.close()
output = p2.communicate()[0]
print("Result bistro : ")
print(output)
end = time()

for o, a in opts:
    if o in ("-t", "--time"):
        print("temps de calcul :")
        print(str(end-begin))
