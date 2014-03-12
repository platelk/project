#!/usr/bin/python2.7

#-*- encodage:Latin1 -*

from pylab import *
from sys import *
from math import *
import random

def     opt_1(t):
    return (3 / (4 - 3 * t))

def     opt_2(t):
    return (exp((5 * t) / 4))

def     opt_3(t):
    return (float(exp((3 * sin(t)) / 2)))

def     opt_4(t):
    return (float(exp(2 * sin(t)) * cos(t**2)))


def     func_opt_1(t, x):
    return (float(x**2))

def     func_opt_2(t, x):
    return (float(x * (1.25)))

def     func_opt_3(t, x):
    return (float(((1.5) * cos(t)) * x))

def     func_opt_4(t, x):
    return (float(2 * (cos(t) - t*tan(t**2)) * x))


if (len(argv) < 3):
    print("Error, not enought parameters")
    exit(1)

if (int(argv[1]) > 4 or int(argv[1] < 1)):
    print("Error, invalid parameter")
    exit(1)

func = {1 : opt_1, 2 : opt_2, 3 : opt_3, 4 : opt_4}
func_opt = {1 : func_opt_1, 2 : func_opt_2, 3 : func_opt_3, 4 : func_opt_4}
i = 0.0

try:
    it = 1.0 / float(argv[2])
except:
    print("Error type")

x = list()
y = list()
y_app = list()
x_app = list()
t = list()

while i <= 1.5:
    y.append(func[int(argv[1])](i))
    x.append(i)
    x_app.append(i)
    if (i == 0.0 and int(argv[1]) == 1):
        y_app.append(0.75)
    elif (i == 0.0):
        y_app.append(1.0)
    else:
        y_app.append(y_app[len(y_app) - 1] + (it * func_opt[int(argv[1])](x_app[len(x_app) - 1], y_app[len(y_app) - 1])))

    try:
        i += it
    except:
        print("Error type")

plot(x, y, "r", x_app, y_app, "g")
ylabel('Ordonne')
ylim(0, 5)
xlabel('Abscisse')
xlim(0, 1)
grid(True)
show()
