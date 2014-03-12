#!/usr/bin/python2.7

# -*-coding:Latin-1 -*

from sys import *
from getopt import *
from os import *

if (len(argv) < 2):
    print("Error, give a Number of option")
    exit(1)

try:
    opt, av = getopt(argv[1:], "ihpsrcl", ["ip", "help", "port", "stop", "run", "compile", "lenght"])
except GetoptError:
    print("Error option")

port = "31337"
ip = "localhost"
pos_id = 0
path = "/home/vink/projet/secu/pepito/source"
func = {1 : "ChangePassword", 2 : "DisplayRecipes", 3 : "DisplayStock", 4 : "MakeRecipe", 5 : "MakeSecretRecipes", 6 : "SaleGranola", 7 : "BuyIngredient"}


for o, a in opt:
    if o in ("-i", "--ip"):
        ip = av[pos_id]
        pos_id += 1
    if o in ("-h", "--help"):
        print("Help\n")
        print(func)
        exit(0)
    if o in ("-p", "--port"):
        port = av[pos_id]
        pos_id += 1
    if o in ("-s", "--stop"):
        system("env -i LD_LIBRARY_PATH=" + path + "/lib_linux " + path + "/pepito stop")
        exit(1)
    if o in ("-r", "--run"):
        system("env -i LD_LIBRARY_PATH=" + path + "/lib_linux " + path + "/pepito start")
        exit(1)
i = 1
cmd = "echo \" "

cmd += av[pos_id]
while i < len(av[pos_id:]):
    cmd += " "
    for o, a in opt:
        if o in ("-l", "--lenght"):
            cmd += str(len(av[pos_id + i]))
    cmd += av[pos_id + i]
    i += 1
cmd += "\""
cmd = cmd + " | nc " + ip + " " + port
print("[" + func[i - 1] + "]\n")
print(cmd)
system(cmd)
exit(1)
