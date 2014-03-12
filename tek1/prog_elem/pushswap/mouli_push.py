#!/usr/bin/python2.7

# -*-coding:Latin-1 -*

##Mouli_push by platel_k

from os import *
from sys import *
from subprocess import *
import commands
from getopt import *
import time



try:
    opts, args = getopt(argv[1:], "hfsc", ["help", "file", "show", "count"])
except GetoptError:
    print("Usage : ./mouli_push --[hdsk] arg1 arg2 ...")
    print("Use -h for more information")
    exit(2)
for o, a in opts:
    if o in ("-h", "--help"):
        print("Usage : ./mouli_push --[hds] arg1 arg2 ...")
        print("Use -f to select a file")
        print("Example: ./pushswap -f file_1 file_2 ...")
        print("Use -s to show operation")
        print("Example: ./pushswap -s arg1 arg2 arg3 ...")
        exit(1)
i = 0
timer = list()
nbr = list()
nbr_arg = list()
time_tot = 0
timer_aff = list();

for o, a in opts:
    if o in ("-f", "--file"):
        while (i < len(args)):
            arg = popen("cat " + args[i])
            nbr_arg.append(len((arg.read()).split()))
            print("calcul time " + args[i] + "...")
            begin = time.time()
            system("./push_swap " + "`cat " + args[i] + "` >> /dev/null")
            end = time.time()
            for o, a in opts:
                if o in ("-c", "--count"):
                    print("calcul operation" + args[i] + "...")
                    p3 = popen("./push_swap " + "`cat " + args[i] + "`")
                    result = p3.read();
                    coup = (str(result)).split()
                    nbr.append(len(coup))
            timer.append(end - begin)
            for o, a in opts:
                if o in ("-s", "--show"):
                    begin = time.time()
                    system("./push_swap " + "`cat " + args[i] + "`")
                    end = time.time()
                    timer_aff.append(end - begin)
            print("Result : ")
            print(args[i] + " : " + str(nbr_arg[i]) + " element")
            print("\t time : " + str(timer[i]))
            for o, a in opts:
                if o in ("-s", "--show"):
                    print("\t time with aff: " + str(timer_aff[i]))
            time_tot = time_tot + timer[i]
            for o, a in opts:
                if o in ("-c", "--count"):
                    print("\t coup : " + str(nbr[i]))
            i = i + 1
        print("time total : " + str(time_tot))

if i == 0:
    argument = " ".join(args)
    begin = time.time()
    p3 = popen("./push_swap " + str(argument));
    result = p3.read()
    end = time.time()
    timer.append((end - begin))
    coup = (str(result)).split()
    nbr.append(len(coup))
    print(argument + " : " + str(len(args)) + " element")
    print("\t time : " + str(timer[i]))
    print("\t coup : " + str(nbr[i]))
    i = i + 1
