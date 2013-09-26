#!/usr/bin/python3.3

import os
import sys
import time
from sys import *
import socket
from getopt import *

action = []
user = "159753admin159753"


def     makeRequest(action, user, *param):
    req = '&&'
    req += str(action)
    req += "::"
    req += str(user)
    for p in param:
        req += '::' + p
    req += '&&'
    return (str(req))

def     sendRequest(conn, req):
    conn.send(bytes(str(req), "ascii"))
def     usage():
    print("Client usage:")
    print("-c || --correction '/path/your_python_file.py' == corrige l'exercice")
    print("-t || --list-tips == affiche la liste des astuces disponible")
    print("-b || --buy-tips id_of_tips == achete une astuce")
    print("-s || --score == affiche votre score")
    print("-r || --credit == affiche votre total de credit")
    print("-a || --achievement == affiche vos HF")
    print("-h || --history == affiche votre historoque")
    print("-m || --my-tips == affiche la liste de vos tips")
    print("-g || --get-subject == affiche le sujet de l'exo en cours")
    print("-A || --add LANGAGE == ajoute LANGAGE a votre liste de langage")
    print("-S || --select LANGAGE == selectionne LANGAGE")
    print("-L || --list == liste les LANGAGE en cours")
    print("-M || --my-level == affiche votre niveau en cours")
    print("-u || --current-lang == affiche le LANGAGE selectionne")
    print("-G || --get-tips == recupere un tips")
    print("-i || --list-lesson == affiche les cours")

def     main():
    conn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        opts, args = getopt(argv[1:], "c:tb:srahmgl:A:S:LMGui", ["correction=", "list-tips", "buy-tips=", "score", "credit", "achievement", "history", "my-tips", "get-subject", "language=", "add=", "select=", "my-level=", "get-tips=", "current-lang", "list-lesson"])
    except:
        print("option error.")
        exit(1)
    # if (len(opts) == 0):
    #     usage()
    #     exit(0)

#    try:
    conn.connect(("10.19.252.191", 8582))
#    except:
#        print("Error connection.")
#        exit(1)
    index = 0
    argument = list()
    conn.settimeout(3)
    sendRequest(conn, makeRequest(int(sys.argv[1]), user, *(sys.argv[2:])))
    for o, a in opts:
        if o in ("-c", "--correction"):
            index = 16
            print("Get test...")
            sendRequest(conn, makeRequest(index, user, *argument))
            ret = ""
            print("Testing...")
            index = 1
            ret = ""
            try:
                try:
                    try:
                        msg = conn.recv(4096)
                    except:
                        msg = ""
                    print(msg)
                    try:
                        s = (msg.decode("ascii")).split("::")
                    except:
                        s = [""]
                    cmd = ""
                    print(s)
                    for t in s:
                        cmd = a + " " + t
                        print(cmd)
                        ret += os.popen(cmd, 'r').read()
                        print("-----")
                    ret = ret.replace("\n", "??")
                    print(ret)
                except:
                    ret = ""
                try:
                    conn.close()
                except:
                    print("Error closing connection")
            except:
                print("error...")
                ret = ""
            conn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            conn.connect(("10.19.252.191", 8582))
            conn.settimeout(3)
            argument.append(ret)
        elif o in ("-t", "--list-tips"):
            index = 7
        elif o in ("-S", "--select"):
            index = 2
            argument.append(a)
        elif o in ("-A", "--add"):
            index = 11
            argument.append(a)
        elif o in ("-L", "--list"):
            index = 3
        elif o in ("-u", "--current-lang"):
            index = 12
        elif o in ("-m", "--my-tips"):
            index = 6
        elif o in ("-s", "--score"):
            index = 5
        elif o in ("-M", "--my-level"):
            index = 4
        elif o in ("-G", "--get-tips"):
            index = 8
            argument.append(a)
        elif o in ("-r", "--credit"):
            index = 9
        elif o in ("-g", "--get-subject"):
            index = 13
        elif o in ("-i", "--list-lesson"):
            index = 14
        elif o in ("-a", "--achievement"):
            index = -1
        elif o in ("-b", "--buy-tips"):
            index = 10
            try:
                argument.append(a)
            except:
                print("Invalide tips")
                conn.close()
                exit(0)
        elif o in ("-l", "--language"):
            index = 2
            argument.append(a)
    print("sending...")
    sendRequest(conn, makeRequest(index, user, *argument))
    try:
        msg = conn.recv(4096)
        print(msg.decode("ascii"))
    except:
        print("end")
    return (0)

###########
main()
