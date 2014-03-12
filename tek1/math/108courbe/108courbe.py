#!/usr/bin/python2.7

#-*- encodage:Latin1 -*

from pylab import *
from sys import *
from math import *
import random

opt = -1
x = list()
y = list()
tab = { 1 : log, 2 : exp, 3 : pow, 4 : cos, 5 : sin, 6 : tan, 7 : cosh, 8 : sinh, 9 : tanh }
try:
    opt = int(argv[1])
except:
    print("Error, give a valid option")
    exit (1)
if (opt < 1 or opt > 10):
    print("Error, please give a option between 1 and 10")
    exit (0)
if (opt == 10):
    opt = random.randrange(1, 10, 1)
if (opt == 1):
    i = 0.00001
else:
    i = -10.0
while i < 10000.0:
    if (opt == 3):
        y.append(pow(0.5, i))
    else:
        y.append(tab[opt](i))
    x.append(i)
    i = i + 0.1
plot(x, y, "k")
ylabel('Ordonne')
ylim(-10, 10)POWNED
xlabel('Abscisse')
xlim(-10, 10)
grid(True)
show()
