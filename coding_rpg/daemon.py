#!/usr/bin/python2.7
#
# Made by platel_k
#

import socket
import hashlib
import time
import signal
import jsonpickle
from sys import *
import os
import ConfigParser
from multiprocessing import Process, Value, Array, Queue, Pipe
from user import *

user = list();

class Connection:
    """
    Class connection symbolyse the connection between user and epitech server.
    """

    def __init__(self, server = '', port_client = 8484):
        self.client_connection = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.connected = False
        self.client_port = port_client
#        try:
        self.logFile = open("./server_log.log", "wb")
        self.logFile.write("============================================\n")
        self.logFile.write("\t{0}\n".format(time.strftime("%a, %d %b %Y %H:%M:%S +0000", time.gmtime())))
        self.logFile.write("============================================\n")
        #        except:
        #           print("Error to open file")
        #          exit(1)
    def read(self, conn):
        string = conn.recv(4096)
        string = string.replace("\n", '')
        return (string)

    def printLog(self, msg):
        self.logFile.write(msg + "\n")
        print msg

    def send(self, conn, msg=''):
        if (len(msg) > 0):
            ret = conn.send(msg + "\n")
            if ret == 0:
                return (False)
            else:
                return (True)
        return (False)

    def getUser(self, conn):
        i = 0
        s = self.read(conn)
        try:
            info = s.split("&&")[1].split("::")
        except:
            return list()
        for u in user:
            if (info[1] == u.name):
                return (info, i)
            i += 1
        self.printLog("New user : {0}".format(info[1]))
        user.append(User(info[1], len(user) - 1))
        return (info, i)

    def exeCommand(self, info, i, conn):
        try:
            n = int(info[0])
        except:
            self.printLog("Error : cmd not valid")
            self.send(conn, str("Error : invalid cmd"))
            return False
        ret = ""
        print(user)
        try:
            if ((n < 1 or n > 16) and user[i].name not in "159753admin159753"):
                self.printLog("Permission denied to execute {} by {}".format(n, user[i].name))
        except:
            self.printLog("Error checking permission.")
            return (0)
        if (user[i].name in "159753admin159753"):
            for a, u in enumerate(user):
                if info[2] in u.name:
                    i = a
                    info = info[1:]
                    break
        try:
            self.printLog("execute \033[1;33m[{0}]\033[1;30m for user \033[1;34m[{1}]\033[1;30m".format((user[i].help().split("\n"))[n], user[i].name))
        except:
            try:
                (user[i].help().split("\n"))[n]
            except:
                print("erreur appel")
            self.printLog("Error [{0}] ({1}) out of the range".format(n, i))
        try:
            if (len(info[2:]) == 0):
                sys.stdout.write(" ... ")
                ret, msg = user[i].functions[n]()
            else:
                sys.stdout.write(" with param {0} ... ".format(*info[2:]))
                ret, msg = user[i].functions[n](*info[2:])
            self.printLog("\033[1;32mSuccess\033[1;30m\nreturn : [{0}] [{1}]\033[1;30m".format(ret, msg))
        except:
            self.printLog("\033[1;31m-> Error : invalide parameter [" + str(ret) + "]\033[1;30m")
            return (False)
        try:
            self.send(conn, str(msg))
        except:
            self.printLog("\033[1;31mError : connection close\033[1;30m")
        return (True)

    def connectClient(self, q = None, m = None, c = None):
        conn = True
        self.printLog("-- Client-server connection ...")
        while conn:
            try:
                self.client_connection.bind(('', self.client_port))
                self.client_connection.listen(60)
                conn = False
            except:
                time.sleep(1)
                continue
            list_users = list()
            self.printLog("-- Client-server conntection success\n")
            if (True):
                while 1:
                    connection, info_conn = self.client_connection.accept()
                    info, i = self.getUser(connection)
                    self.printLog("\nRequest of \033[1;34m{0}\033[1;30m".format(info))
                    try:
                        self.exeCommand(info, i, connection)
                    except:
                        self.printLog("\033[1;31m Error : problem in exec request.\033[1;30m")

    def gestClient(self, conn, q = None, m = None):
        s = self.read(conn);
        self.printLog(s);
        conn.close();


def     main(user="", socks="", port_client=8484):
    client_server = Queue()
    server_client = Queue()
    server_main = Queue()
    client_main = Queue()
    while 1:
        conn = Connection('', port_client)
        try:
            conn.connectClient(client_server, client_main, server_client)
            conn.logFile.close()
            conn.client_connection.close()
        except (KeyboardInterrupt):
            conn.logFile.close()
            conn.client_connection.close()
            exit(0)
            #p_client.terminate()
        except:
            conn.printLog("Insolved error.")
            conn.logFile.close()
            conn.client_connection.close()

## Main
try:
    with open('data.pickle', 'rb') as f:
        u = jsonpickle.decode(f.read())
        for i in u:
            tmp = User(i["name"], i["id"])
            tmp.credit = i["credit"]
            for l in i["language"]:
                print "=================\n"
                try:
                    print l
                    print l["name"]
                    try:
                        tmp.add_language(l["name"], l["current_exo"]["id"])
                    except:
                        print "Error loading language..."
                    for t in l["my_tips"]:
                        try:
                            print "======>>>> " + str(t);
                            tmp.language[-1].my_tips.append(t)
                        except:
                            continue
                except:
                    print "Error...."
                    continue
            user.append(tmp)
        f.close()
        print type(user)
except:
    user = list()
    print "Error..."
try:
    user.append(User("159753admin159753", 0))
    main('', '', 8582)
except:
    os.system("rm data.pickle")
    with open('data.pickle', 'wb') as f:
        for a, i in enumerate(user):
            if ("159753admin159753" in i.name):
                del user[a]
            i.current_language = None;
        f.write(jsonpickle.encode(user))
        f.close()