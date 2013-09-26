#!/usr/bin/python3.3

from user import *

me = User("harold", 0)
while (True):
    res = input(">>> ")
    arg = input("args>>>")
    if (arg == ""):
        t = me.functions[int(res)]()
    else:
        p = arg.split(" ")
        print(p)
        t = me.functions[int(res)](*p)
    print("return value: " + str(t[0]) + "\nresult:\n" + t[1] + "\n")
