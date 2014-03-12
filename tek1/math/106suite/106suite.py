#!/usr/bin/python3

#-*- encodage:Latin1 -*

import matplotlib.pyplot as plt
from sys import *

def     calc(x):
    u_x = x
    try:
        coef = float(argv[1])
    except:
        coef = -1.5
    try:
        x = x**2 + coef
    except:
        return (u_x)
    return (x);

i = 0
try:
    it = int(argv[2])
except:
    it = 10100
try:
    begin = int (argv[3])
except:
    begin = 10000
t = [0]
u = [0.0]
while i < it:
    u.append(calc(u[len(u) - 1]))
    t.append(i)
    i += 1
plt.plot(t, u, "k", t, u, "bo")
plt.ylabel('Ordonne')
plt.ylim(-2, 2)
plt.xlabel('Abscisse')
plt.xlim(begin, it)
plt.grid(True)
plt.show()
