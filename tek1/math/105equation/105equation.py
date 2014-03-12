#!/usr/bin/python2.7

#-*- encodage:Latin1 -*

#Import des bibliotheques

from sys import *
from math import *

#################
#      f(x)     #
#################
def     f(x):
    result = (pow(x, 4) + pow(x, 2) + 4*x - 2)
    return (result)
#################

#################
#      ONE      #
#################
def     opt_one():
    print ("Methode de la bissection")
    i = 0
    x1 = -1.5
    x2 = -1.6
    e = pow(10, -6)
    print ("Point initial x1 = " + str(x1))
    print ("Point initial x2 = " + str(x2))
    try:
        while (i < 100):
            xm = (x1 + x2) / 2
            print("Iteration " + str(i) + " valeur x " + str(xm))
            if ((abs(x1 - x2)) / 2*abs(xm)) < e:
                print("\nConvergence atteinte en " + str(i) + " Iteration")
                print("Solution r = " + str(xm))
                print("Solution racine(r) = " + str(sqrt(abs(xm))))
                print("Solution f(r) = " + str(f(xm)))
                return (0)
            if ((f(x1) * f(xm)) < 0):
                x2 = xm
            else:
                x1 = xm
            i = i + 1
    except:
        print("Erreur, division par zero")
        exit(1)
    print("Convergence non atteinte avec " + str(i) + " iteration")
    return (0)
#################

#################
#      TWO      #
#################
def     opt_two():
    print("Methode Newton")
    i = 0
    x2 = -1.5
    e = pow(10, -6)
    while (i < 100):
        try:
            x1 = x2
            x2 = x2 - (f(x2) / ((4 * pow(x2, 3)) + (2 * x2) + 4))
            print("Iteraation " + str(i) + " valeur x " + str(x2))
            if ((abs(x2 - x1) / abs(x2)) < e):
                print("\nConvergence atteinte en " + str(i) + " Iteration")
                print("Solution r = " + str(x2))
                print("Solution f(r) = " + str(f(x2)))
                return (0)
            i = i + 1
        except:
            print("Erreur division par zero")
            exit(1)
    print("Convergence non atteinte avec " + str(i) + " iteration")
    return (0)
#################

#################
#     THREE     #
#################
def     opt_three():
    x0 = -1.6
    x1 = -1.5
    i = 0
    e = pow(10, -6)
    while (i < 100):
        try:
            x2 = x1 - ((f(x1) * (x1 - x0)) / (f(x1) - (f(x0))))
            print("Iteraation " + str(i) + " valeur x " + str(x2))
            if ((abs(x2 - x1) / (abs(x2))) < e):
                print("\nConvergence atteinte en " + str(i) + " Iteration")
                print("Solution r = " + str(x2))
                print("Solution f(r) = " + str(f(x2)))
                return (1)
            x0 = x1
            x1 = x2
            i = i + 1
        except:
            print("Erreur, division par zero")
            exit (1)
    return (0)
#################

#################
#      MAIN     #
#################
if (len(argv) < 2):
    print("Error, give an option")
    exit (1)

try:
    opt = int(argv[1])
except:
    print("Error, give a number")
    exit(1)
if (opt == 1):
    opt_one()
elif (opt == 2):
    opt_two()
elif (opt == 3):
    opt_three()
else:
    print("Error, bad option")
exit(1)
#################
