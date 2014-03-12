#!/usr/bin/python2.7

#-*- encodage:Latin1 -*

#Import des bibliotheques

## By Platel_k

from sys import *
from math import *
from os import *
from getopt import *
import commands

try:
    opts, args = getopt(argv[1:], "c", ["create"])
except GetoptError:
    print("Error")
    exit(1)
##
## Changer cette ligne ci-dessous par le lien de l'Asm des astek sur VOTRE system
## 

k = 0;
tot_name = list()
name_tot = list()
as_name = list()

while (k < len(args)):
    print("Astek :\n")
    system("./AsmX " + str(args[k]))
    name = args[k].split(".")
    system("mv " + str(name[0]) + ".cor " + str(name[0]) + "_py.cor")
    print("\nYours :\n")
    system("../asm " + str(args[k]))
    you_name = name[0] + "_py.cor"
    my_name = name[0] + ".cor"

    p1 = popen("cat " + you_name)
    p2 = popen("cat " + my_name)

    result_my = p2.read()
    result_you = p1.read()

    i = 0
    n = 0
    error = 0
    print("----------\n\n")
    while i < len(result_my) and i < len(result_you):
        if (result_my[i] != result_you[i]):
            print("\n\033[37m In octect \033[34m" + str(i) + "\033[37m" + " ( ligne -> "+ str(hex((i)/ 16)) + "0 colonne -> " + str(hex(i %16)) + ")")
            print("\033[37mYou => \033[31m" + str(hex(ord(result_my[i]))) + "\033[37m ( \033[32m" +
                  str(ord(result_my[i])) +"\033[37m )" + " is different of \033[37mAstek => \033[31m" +
                  str(hex(ord(result_you[i]))) + "\033[37m ( \033[32m" + str(ord(result_you[i])) +"\033[37m )")
            error += 1
        i += 1
    print ("________________\n")
    print ("  \033[31mTotal error = " + str(error) + "\033[37m")
    print ("\n________________\n")
    if i < len(result_my):
        print("You have more octect than Astek")
    if i < len(result_you):
        print("Astek have more octect than you")
        as_name.append(name[0])
    if (error > 0):
        tot_name.append(name[0])
    else:
        name_tot.append(name[0])
    k = k + 1
print ("Champ with error :")
print (tot_name)
print ("Champ without error :")
print (name_tot)
print ("Assemblig fail")
print (as_name)
