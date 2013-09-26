#!/usr/bin/python3.3

import os
import time
from sys import *
import socket
from getopt import *

action = []
user = os.environ["USER"]

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

def     main():
    conn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        opts, args = getopt(argv[1:], "c:tb:srahmg", ["correction=", "list-tips", "buy-tips=", "score", "credit", "achievement", "history", "my-tips", "get-subject"])
    except:
        print("option error.")
        exit(1)
    if (len(opts) == 0):
        usage()
        exit(0)

#    try:
    conn.connect(("10.19.252.191", 8585))
#    except:
#        print("Error connection.")
#        exit(1)
    index = 0
    argument = list()
    conn.settimeout(3)
    for o, a in opts:
        if o in ("-c", "--correction"):
            index = 8
            print("Get test...")
            sendRequest(conn, makeRequest(index, user, *argument))
            ret = ""
            print("Testing...")
            index = 7
            try:
                try:
                    msg = conn.recv(4096)
                    s = (msg.decode("ascii")).split("::")
                    cmd = ""
                    for t in s:
                        cmd = a + " " + t
                        ret += os.popen(cmd, 'r').read()
                except:
                    ret = ""
                conn.close()
                time.spleep(2)
            except:
                print("error...")
                ret = ""
            conn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            conn.connect(("10.19.252.191", 8585))
            conn.settimeout(3)
            argument.append(ret)
        elif o in ("-t", "--list-tips"):
            index = 0
        elif o in ("-m", "--my-tips"):
            index = 1
        elif o in ("-s", "--score"):
            index = 3
        elif o in ("-r", "--credit"):
            index = 4
        elif o in ("-h", "--history"):
            index = 5
        elif o in ("-g", "--get-subject"):
            index = 9
        elif o in ("-a", "--achievement"):
            index = 6
        elif o in ("-b", "--buy-tips"):
            index = 2
            try:
                argument.append(a)
            except:
                print("Invalide tips")
                conn.close()
                exit(0)
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