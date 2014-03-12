#!/usr/bin/python2.7

#-*- encodage:Latin1 -*

from pylab import *
from sys import *

def     fun_calc(x, y, n, px):
    p = 0.0
    i = 0
    while i < n:
        s = y[i]
        j = 0
        while j < n:
            if i != j:
                s = s * ((px - x[j]) / (x[i] - x[j]))
            j += 1
        p += s
        i += 1
    return (p)


x = [0.0, 1.0, 2.0, 3.0, 5.0, 6.0]
y = [2.0, 6.0, 8.0, 3.0, 7.0, 5.0]
res = list()
y_res = list()
i = -10.0

while i < 10.0:
    res.append(fun_calc(x, y, len(x), i))
    i += 0.01
    y_res.append(i)

plot(y_res, res, "k", x, y, "bo")
ylabel('Ordonne')
ylim(-2, 10)
xlabel('Abscisse')
xlim(-2, 10)
grid(True)
show()
