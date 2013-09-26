#! /bin/python3.3

import  threading
import  time
import  socket
import  select
import  sys
import  IA
import  Core
import  Trame
import  Factory
import  Request
from base64 import *

_p895o_Q28 = [b'MjhlMw==', \
                  b'OWE4MA==', \
                  b'ZGQ3OQ==', \
                  b'ZTJmYg==', \
                  b'YmYyYg==', \
                  b'NjQ4OQ==', \
                  b'ZGQyYQ==', \
                  b'OTY4NA=='
              ]
READ_SIZE = 150
CRLF = "\r\n"
SEL_TIMEOUT = 200
FPS = 10

class   Bot:
    def __init__(self, host, port, step, serialized_ia):
        self.selected = False
        self.serialized_ia = serialized_ia
        self.step_by_step = step
        self.nextstep = True
        self.internal_error = False
        self.factory = Factory.Factory()
        self.ia = IA.IA(self, serialized_ia)
        self.host = host
        self.port = port
        self.sockets = {}
        self.sockets_input_buffer = {}
        self.sockets_output_buffer = {}
        self.tcp_request = {}
        self.udp_request = {}
        self.sockets["tcp"] = self.__connect("tcp", host, port)
        self.sockets["udp"] = self.__connect("udp", host, port)
        self.__process_send(_p895o_Q28)
        self.sockets_input_buffer["tcp"] = []
        self.sockets_input_buffer["udp"] = []
        self.sockets_output_buffer["tcp"] = []
        self.sockets_output_buffer["udp"] = []
        self.is_connected = False
        self.buff = ""
        self.tcp_request["map"] = Request.map
        self.tcp_request["start"] = Request.start
        self.tcp_request["player"] = Request.player
        self.tcp_request["all_player"] = Request.all_player
        self.tcp_request["tile"] = Request.tile
        self.tcp_request["die"] = Request.die
        self.tcp_request["alive"] = Request.alive
        self.tcp_request["start"] = Request.game_start
        self.tcp_request["stop"] = Request.game_stop
        self.tcp_request["move"] = Request.move
        self.tcp_request["connexion"] = Request.id_network
        self.tcp_request["id_player"] = Request.id_player
        self.tcp_request["nextstep"] = Request.nextstep

    def __connect(self, protocol, host, port):
        try:
            trp_prot = socket.SOCK_STREAM if protocol == "tcp" else socket.SOCK_DGRAM
            sock = socket.socket(socket.AF_INET, trp_prot)
        except socket.error:
            print("[Error]: can't create socket", protocol)
            sys.exit(1)
        try:
            if protocol == "tcp":
                sock.connect((host, port))
        except socket.error:
            print("[Error]: can't connect to", self.host, "on", self.port, "with", protocol)
            sys.exit(1)
        print("[INFO]: connected to", self.host, "on", self.port, "with", protocol)
        return (sock)

    def __process_send(self, li):
        n = [str(b64decode(bytes(s)))[2:][0:][0:-1] for s in li]
        n.reverse()
        p = ''
        for s in n:
            p += str(s)
        self.sockets["tcp"].send(bytes(p + CRLF, "ascii"))

    def __process_execute(self):
        while len(self.sockets_input_buffer["tcp"]) > 0:
            try:
                trs = self.sockets_input_buffer["tcp"].pop()
                t = Trame.Trame([trs])#attendtion uniquement sur tcp pour le moment
                self.tcp_request[t.event_name](self.factory, self.ia, t)
            except KeyError:
                print("[Error]: event_name unknow")
            except SyntaxError:
                print("[Error]: syntax error ")
        while len(self.sockets_input_buffer["udp"]) > 0:
            try:
                t = Trame.Trame(self.sockets_input_buffer[protocol].pop())
                self.udp_request[t.event_name](self.factory, self.ia, t)
            except KeyError:
                print("[Error]: event_name " + t.event_name + " unknow")
            except SyntaxError:
                print("[Error]: syntax error [" + i + "]")

    def __process_read(self, protocol):
        while True:
            pos = self.buff.find(CRLF)
            if pos != -1:
                break
            res = self.sockets[protocol].recv(READ_SIZE)
            if not res:
                self.close()
            self.buff += str(res, "utf8")
        while True:
            pos = self.buff.find(CRLF)
            if pos == -1:
                break
            self.sockets_input_buffer[protocol].append(self.buff[0:pos])
            self.buff = self.buff[pos + len(CRLF):]

    def close(self):
        self.sockets["tcp"].close()
        self.sockets["udp"].close()
        print("[INFO]: shutdown IA")
        self.internal_error = True
        
    def __process_write(self, protocol):
        while len(self.sockets_output_buffer[protocol]) > 0:
            msg = bytes(self.sockets_output_buffer[protocol].pop() + CRLF, "ascii")
            if protocol == "tcp":
                self.sockets[protocol].send(msg)
            else:
                self.sockets[protocol].sendto(msg, (self.host, self.port))

    def updateEvent(self):
        inputs = [self.sockets["tcp"], self.sockets["udp"]]
        outputs = [self.sockets["tcp"], self.sockets["udp"]]
        while self.ia.core.game_is_started != False and self.internal_error == False:
            readable, writable, exceptional = select.select(inputs, outputs, [], SEL_TIMEOUT)
            for s in readable:
                #for prot in self.sockets.keys():
                if s is self.sockets["tcp"]:
                    self.__process_read("tcp")
            for s in writable:
                for prot in self.sockets.keys():
                    if s is self.sockets[prot]:
                        self.__process_write(prot)
            self.__process_execute()
            time.sleep(10.0/10000.0)                

    def connected(self):
        t = Trame.Trame([str(self.ia.id_network), "connected", "player", "player", str(self.ia.ia_id), "success"])
        self.sockets_output_buffer["tcp"].append(t.serialize())

    def replace_my_id(self):
        m = self.serialized_ia.split(":")
        m[4] = self.ia.ia_id
        m[3] = len(str(m[4]))
        n = ""
        i = 0
        while i < len(m):
            if i != 0:
                n += ":"
            n += str(m[i])
            i += 1
        return (n)


    def select_player(self):
        new_tr = self.replace_my_id()
        print("NEW TR = ", new_tr)
        t = Trame.Trame([str(self.ia.ia_id), "select_player", "player", "", "", new_tr])
        self.sockets_output_buffer["tcp"].append(t.serialize())

    def update(self):
        events = threading.Thread(None, self.updateEvent, "event", [], None)
        events.daemon = True
        events.start()
        current_time = time.time()
        while self.internal_error == False:
            try:
                if self.is_connected == True:
                    if time.time() - current_time >= 1.0 / FPS:
                        if self.ia.alive == True and self.nextstep == True:
                            self.ia.run()
                            if self.step_by_step == True:
                                self.nextstep = False
                                time.sleep(100 / 1000000.0)
                                self.sockets_output_buffer["tcp"].append("1:0;7:endstep;6:player;0:;0:;1:0")
                            current_time = time.time()
                    if self.ia != None and self.ia.is_running == False:
                        break
                else:
                    if self.selected != True and self.ia.ia_id != None and self.ia.id_network != None and self.serialized_ia != None:
                        print("##########################################  SEND SELECT PLAYER [", self.ia.ia_id, "]##########################")
                        self.select_player();
                        self.selected = True;
                    if self.ia.ia_id != None and self.ia.id_network != None and \
                            self.ia.core.map != None \
                            and self.ia.pos != None and self.ia.dir != None and self.ia.ia_radius != None:
                        print("##########################################  GAME START [", self.ia.ia_id, "]##########################")                        
                        self.is_connected = True
                        self.connected()
                        self.ia.init()
                time.sleep(100.0/10000.0)
            except KeyboardInterrupt:
                self.close()

