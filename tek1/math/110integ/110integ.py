#!/usr/bin/python2.7

from sys import *
from math import *

def     f_one(x):
    return (1.0)

def     f_two(x):
    return (2.0 * x)

def     f_three(x):
    return (3.0 * x**2)

def     f_four(x):
    return (4.0 * x**3)

def     f_five(x):
    return (5.0 * x**4)

def     f_six(x):
    return (6.0 * x**5)

def     f_seven(x):
    return (1.0 / (2.0 * (sqrt(2.0) - 1.0) * sqrt(x + 1.0)))

def     f_hight(x):
    return (2.0 / (x + 1.0)**2)

def     f_nine(x):
    return ((3.14 / 2.0) * sin((3.14 / 2.0) * x))

def     f_ten(x):
    return (exp(x) / (exp(1.0) - 1.0))


def     rect(f, n):
    i = 0.0
    integ = 0.0
    while (i < n):
        integ += f(i * 1.0 / n)
        i += 1.0
    integ *= 1.0 / n
    return (integ)

def     trap(f, x):
    i = 1.0
    integ = 0.0
    while (i < n):
        integ += f(i * 1.0 / n)
        i += 1.0
    integ = (2.0 * integ + f(0.0) + f(1.0)) * (1.0 / (2.0 * n))
    return (integ)

def     simpson(f, x):
    i = 1.0
    integ = 0.0
    integ2 = 0.0
    while (i < n):
        integ += f(i * 1.0 / n)
        i += 1.0
    i = 0.0
    while (i < n):
        integ2 += f((1.0 * i / n) + ((1.0 / n) / 2.0))
        i += 1.0
    integ = 1.0 / (6.0 * n) * (f(0.0) + f(1.0) + 2.0 * integ + 4.0 * integ2)
    return (integ)

def     gauss(f, x):
    integ = 0.0
    integ = (5.0 / 18.0) * f((1.0 - sqrt(3.0 / 5.0)) * (1.0 / 2.0)) + (8.0 / 18.0) * f(1.0 / 2.0) + (5.0 / 18.0) * f((1.0 + sqrt(3.0 / 5.0)) * (1.0 / 2.0))
    return (integ)



if (len(argv) < 2):
    print ("Please give a argument")
    exit(1)

try:
    n = float(argv[1])
except:
    print ("Error [" + argv[1] + "] is not a valid argument")
    exit(1)

if (n < 10 or n > 100):
    print ("Error 'n' must be beetween 10 and 100")
    exit(1)

f = {1 : f_one, 2 : f_two, 3 : f_three, 4 : f_four, 
     5 : f_five, 6 : f_six, 7 : f_seven, 8 : f_hight, 9 : f_nine, 10 : f_ten}
d = {1 : rect, 2 : trap, 3 : simpson, 4 : gauss}

t = 0
i = 1
print ("\n _______________________________________________________________")
print ("| n = " + str(n) + "\t| Rectangle |  Trapeze  |  Simpson  |   Gauss   |")
print ("|_______________|___________|___________|___________|___________|")

while (i <= 10):
    stdout.write ("| f" + str(i) + "\t\t|")
    stdout.write ("  " + "%.1e"%abs(1 - d[1](f[i], n)) + "  |")
    stdout.write ("  " + "%.1e"%abs(1 - d[2](f[i], n)) + "  |")
    stdout.write ("  " + "%.1e"%abs(1 - d[3](f[i], n)) + "  |")
    stdout.write ("  " + "%.1e"%(abs(1 - d[4](f[i], n)) * (1 / pow(n, 4.0))) + "  |")
    print ("\n|_______________|___________|___________|___________|___________|")
    i += 1

print ("\n")
