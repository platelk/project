#!/usr/bin/python2.7

#-*- encodage:Latin1 -*

#Import des bibliotheques

from sys import *
from math import *


# Vecteur directeur de la droite
#      u(ux, uy, uz)
#Point appartenant a la droite
#      p(x, y, z)

#Equation parametrique de la droite
#     Px = ux*k + x
#     Py = uy*k + y
#     Pz = uz*k + z

#CALC_CYL
##Fonction de calcule
##Formule cylindre = "(x - x0)^2 + (y - y0)^2 = R^2"
1
#========================
def     calc_cyl(x, y, z, ux, uy, uz, r):
    print("CYLINDRE de rayon = " + str(r))
    print("DROITE passant par le point (" + str(x) + ", " + str(y) + ", " + str(z) + ")")
    print("et de vecteur directeur (" + str(ux) + ", " + str(uy) + ", " + str(uz) + ")")
    #Resolution de l'equation pour trouver K
    a = ux + uy
    b = 2 * (x*ux + y*uy)
    c = x**2 + y**2 - r**2
    #Calcule de DELTA
    delta = (b**2) - (4*a*c)
    if delta > 0 and a > 0:
        print("Nombre de point d'intersection = 2")
        #calcule des solutions
        x1 = (b - sqrt(delta)) / (2*a)
        x2 = (b + sqrt(delta)) / (2*a)
        print("Point 1 (" + str(x1*ux + x) + ", " + str(x1*uy + y) + ", " + str(x1*uz + z) + ")")
        print("Point 2 (" + str(x2*ux + x) + ", " + str(x2*uy + y) + ", " + str(x2*uz + z) + ")")
    elif delta == 0:
        print("Nombre de point d'intersection = 1")
        #calcule de la solution
        x1 = (b) / (2*a)
        print("Point (" + str(x1*ux + x) + ", " + str(x1*uy + y) + ", " + str(x1*uz + z) + ")")
    else:
        print("Aucune intersection.")
    return (0)
#========================

#CALC_SPH
#Fonction de calcule
##Formule sphere = "(x - x0)^2 + (y - y0)^2 + (z - z0)^2 = R^2"

#========================
def     calc_sph(x, y, z, ux, uy, uz, r):
    print("SPHERE de rayon = " + str(r))
    print("DROITE passant par le point (" + str(x) + ", " + str(y) + ", " + str(z) + ")")
    print("et de vecteur directeur (" + str(ux) + ", " + str(uy) + ", " + str(uz) + ")")
    #Resolution de l'equation pour trouver K
    a = (ux + uy + uz)
    b = 2*(x*ux + uy*y + z*uz)
    c = x**2 + y**2 + z**2 - r**2
    #Calcule de DELTA
    delta = (b**2) - (4*a*c)
    if delta > 0 and a > 0:
        print("Nombre de point d'intersection = 2")
        #calcule des solutions
        x1 = (-b - sqrt(delta)) / (2*a)
        x2 = (-b + sqrt(delta)) / (2*a)
        print("Point 1 (" + str(x1*ux + x) + ", " + str(x1*uy + y) + ", " + str(x1*uz + z) + ")")
        print("Point 2 (" + str(x2*ux + x) + ", " + str(x2*uy + y) + ", " + str(x2*uz + z) + ")")
    elif delta == 0:
        #calcule de la solution
        print("Nombre de point d'intersection = 1")
        x1 = (-b) / (2*a)
        print("Point (" + str(x1*ux + x) + ", " + str(x1*uy + y) + ", " + str(x1*uz + z) + ")")
    else:
        print("Aucune intersection.")
    return (0)
#========================

#CALC_CON
##Formule cone = "x^2 + y^2 = z^2 * tan2(A)"

#========================
def     calc_con(x, y, z, ux, uy, uz, A):
    print("CONE d'angle = " + str(A) + " degree")
    print("DROITE passant par le point (" + str(x) + ", " + str(y) + ", " + str(z) + ")")
    print("et de vecteur directeur (" + str(ux) + ", " + str(uy) + ", " + str(uz) + ")")
    #Resolution de l'equation pour trouver K
    a = (ux + uy - (uz * pow(tan(radians(A)), 2)))
    b = 2*((x * ux) + (y * uy) - (z * uz * pow(tan(radians(A)), 2)))
    c = ((x**2) + (y**2) - ((z*z) * pow(tan(radians(A)), 2)))
    #Calcule de DELTA
    delta = (b*b) - (4*a*c)
    if delta > 0 and a > 0:
        print("Nombre de point d'intersection = 2")
        #calcule des solutions
        x1 = (-b - sqrt(delta)) / (2*a)
        x2 = (-b + sqrt(delta)) / (2*a)
        print("Point 1 (" + str(x1*ux + x) + ", " + str(x1*uy + y) + ", " + str(x1*uz + z) + ")")
        print("Point 2 (" + str(x2*ux + x) + ", " + str(x2*uy + y) + ", " + str(x2*uz + z) + ")")
    elif delta == 0:
        #calcule de la solution
        print("Nombre de point d'intersection = 1")
        x1 = (b) / (2*a)
        print("Point (" + str(x1*ux + x) + ", " + str(x1*uy + y) + ", " + str(x1*uz + z) + ")")
    else:
        print("Aucune intersection.")
    return (0)
#========================

#MAIN
#-------------------------
#Regarde si l'utilisateur a rentre le bon nombre de parametre
if len(argv) < 9:
    print("Erreur, pas assez d'argument")
    exit (1)

#Regarde si l'option est un chiffre
try:
    opt = int(argv[1])
except:
    print("Erreur, Option incorrect");
    exit(1);

#Regarde si les parametre rentree par l'utilisateur son des chiffres
if (opt == 1):
    try:
        calc_cyl(int(argv[2]), int(argv[3]), int(argv[4]), int(argv[5]), int(argv[6]), int(argv[7]), int(argv[8]))
    except:
        print("Erreur: veuilliez entrer des nombres s'il vous plait");
        exit(1);
elif (opt == 2):
    try:
        calc_sph(int(argv[2]), int(argv[3]), int(argv[4]), int(argv[5]), int(argv[6]), int(argv[7]), int(argv[8]))
    except:
        print("Erreur: veuilliez entrer des nombres s'il vous plait");
        exit(1);
elif (opt == 3):
    try:
        calc_con(int(argv[2]), int(argv[3]), int(argv[4]), int(argv[5]), int(argv[6]), int(argv[7]), int(argv[8]))
    except:
        print("Erreur: veuilliez entrer des nombres s'il vous plait");
        exit(1);
else:
    print("Erreur, option invalide")
exit(1)
#-------------------------
