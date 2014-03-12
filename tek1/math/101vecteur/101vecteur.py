#!/usr/bin/python2.7

#-*- encodage:Latin1 -*

from sys  import *
from math import *
from random import *


# Fonction for option 1
#//////////////////////////////////////////////
def     opt1():
    if len(argv) < 3:
        print("Given number of dimension")
        exit(1)
    dim = int(argv[2])
    i = 0
    vect1 = list(range(dim))
    vect2 = list(range(dim))
    scalaire = 0
#print addition of vect1 and vect2
    stdout.write("Vecteur u  Vecteur v      Vecteur u + v\n")
    while i < dim:
        vect1[i] = randint(0, 9)
        stdout.write(str(vect1[i]) + '\t\t')
        vect2[i] = randint(0, 9)
        stdout.write(str(vect2[i]) + '\t\t')
        stdout.write(str(vect1[i] + vect2[i]) + '\n')
        i+=1
#print multiplication of vect1 and the number p
    i = 0
    p = randint(0, 9)
    stdout.write("\nNombre p = " + str(p))
    stdout.write("\nVecteur u  Vecteur p.u\n")
    while i < dim:
        stdout.write(str(vect1[i]) + '\t\t')
        stdout.write(str(vect1[i] * p) + '\n')
        scalaire = scalaire + (vect1[i] * vect2[i])
        i+=1
#print scalaire of vect1 and vect2
    stdout.write("\nProduit scalaire (u, v) = " + str(scalaire) + "\n")
    exit(0)
#//////////////////////////////////////////////

#function for opt2
#//////////////////////////////////////////////
def     opt2():
    i = 0
    vect1 = list(range(3))
    vect2 = list(range(3))
    stdout.write("Vecteur u    Vecteur v    Vecteur u vect v\n")
    while i < 3:
        vect1[i] = randint(0, 9)
        vect2[i] = randint(0, 9)
        i += 1
    vect_result = list(range(3))
    vect_result[0] = (vect1[1]*vect2[2])-(vect1[2]*vect2[1])
    vect_result[1] = (vect1[2]*vect2[0])-(vect1[0]*vect2[2])
    vect_result[2] = (vect1[0]*vect2[1])-(vect1[1]*vect2[0])
    i = 0
    while i < 3:
        stdout.write("    " + str(vect1[i]) + '\t\t')
        stdout.write(str(vect2[i]) + '\t\t')
        stdout.write(str(vect_result[i]) + '\n')
        i += 1
    print("\nNorme de ||u|| = " + str(sqrt(pow(vect1[0], 2) + pow(vect1[1], 2) + pow(vect1[2], 2))))
    print("Norme de ||u ^ v|| = " + str(sqrt(pow(vect_result[0], 2) + pow(vect_result[1], 2) + pow(vect_result[2], 2))))
    exit(0)
#//////////////////////////////////////////////

#function for opt 3
#//////////////////////////////////////////////
def     opt3():
    vect1 = list(range(3))
    vect2 = list(range(3))
    scalaire = 0
    i = 0
    while i < 3:
        vect1[i] = randint(0, 9)
        vect2[i] = randint(0, 9)
        scalaire = scalaire + (vect1[i] * vect2[i])
        i += 1
    norme_vect1 = sqrt(pow(vect1[0], 2) + pow(vect1[1], 2) + pow(vect1[2], 2))
    norme_vect2 = sqrt(pow(vect2[0], 2) + pow(vect2[1], 2) + pow(vect2[2], 2))
    print ("Angle (u, v) = " + str(acos(scalaire / (norme_vect1 * norme_vect2))) + "(en rad)")
    print ("Angle (u, v) = " + str(degrees(acos(scalaire / (norme_vect1 * norme_vect2)))) + "(en degre)")
#//////////////////////////////////////////////

#Main of programme
#//////////////////////////////////////////////
if len(argv) < 2:
        print("Given a option")
        exit(1)
try:
    option = int(argv[1])
except:
    print "Error : give a number please"
    exit(1)

if (option == 1):
    opt1();
if (option == 2):
    opt2();
if (option == 3):
    opt3();
exit(0)
#//////////////////////////////////////////////
