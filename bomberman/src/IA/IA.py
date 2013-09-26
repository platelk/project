#! /bin/python3.3

import  Bot
import  sys
import  math
import  collide
import  Trame
import  UserInterface
import  Core

BOUND_UNIT = 16
CASE_SIZE = 32
IA_FPS = 60
NBR_POSITIONS = 12
STEP_POSITION = 360 / NBR_POSITIONS

class   IA:
    def __init__(self, bot, serialized_ia):
        self.is_running = None
        self.alive = True
        self.bot = bot
        self.id_network = None
        self.ia_id = None
        self.pos = None
        self.dir = None
        self.core = Core.Core()
        self.directions = []
        self.speed = 5
        self.ia_radius = None
        self.bombs = []
        for step in range(NBR_POSITIONS):
            self.directions.append(step * STEP_POSITION)
            
    def updateIA(self, player):
        try:
            life = player.getComponent("life")
            position = player.getComponent("position")
            colider = player.getComponent("colider")
            self.ia_radius = colider.circle[0][3]
            self.pos = (position.x, position.y, position.z)
            self.dir = (position.dx, position.dy, position.dz)
            self.ia_life = life.life
        except (IndexError, NameError):
            raise SyntaxError("missing component or values")

    def removeBomb(self, name):
        ia.core.timer.delTimer(name)

    def addBomb(self, bomb):
        explose = bomb.getComponent("explose")
        name = "bomb:" + str(ret.id)
        ia.core.timer.addTimer(name, "after", explose.timeout, self.removeBomb, [name])

    def noCollision(self, pos):
        if self.core.map != None:
            for i in self.core.map.collide:
                o = i.getComponent("position")
                obj_pos = (o.x, o.y, o.z)
                if i.getComponent("colider").collide(obj_pos, pos, self.ia_radius) == True:
                    self.log("[INFO]: collision here [" + str(pos[0]) + "][" + str(pos[1]) + "]");
                    return (False)
            return (True)
        return (False)

    def pointIsInCircle(self, point, pos_circle, radius):
        ran = math.fabs(math.sqrt((point[0] - pos_circle[0])**2 + (point[1] - pos_circle[1])**2))
        return (ran < circle)

    def dirToPos(self, pos, direction):
        new_dir = (self.speed * math.cos(direction), self.speed * math.sin(direction))
        new_pos = (pos[0] + new_dir[0], pos[1] + new_dir[1])
        return (new_pos)

    def range(self, pos1, pos2):
        return (math.fabs(math.sqrt((pos2[0] - pos1[0])**2 + (pos2[1] - pos1[1])**2)))

    def headFor(self, pos1, pos2):
        vec = (pos2[0] - pos1[0], pos2[1] - pos1[1])
        angle = math.degrees(math.atan2(vec[1], vec[0]))
        if angle < 0:
            angle = 360 + angle
        idx = round(angle / STEP_POSITION)
        if idx < NBR_POSITIONS:
            return (self.directions[idx])

    def getMyPos(self):
        return (self.pos)

    def getMyDir(self):
        return (self.dir)

    def getMyRadius(self):
        return (self.ia_radius)

    def getNbrBombs(self):
        return (len(self.bombs))

    def getPossibleDirections(self):
        return (self.directions)

    def move(self, direction):
        print("[ACTION]: move")
        new_dir = (math.cos(direction), math.sin(direction))
        new_pos = (self.pos[0] + new_dir[0], self.pos[1] + new_dir[1])
        data = str(float(new_dir[0])) + "|" + str(float(new_dir[1])) + "|" + str(float(self.dir[2]))
        t = Trame.Trame([str(self.id_network), "move", "player", "", str(self.ia_id), data])
        if (self.bot.step_by_step == True):
            self.bot.sockets_output_buffer["tcp"].append(t.serialize())
        else:
            self.bot.sockets_output_buffer["udp"].append(str(self.id_network) + "@" + t.serialize())

    def run(self):
        self.log("[INFO]: run IA");
        UserInterface.run(self)

    def init(self):
        self.log("[INFO]: init IA");
        UserInterface.init(self)

    def log(self, data):
        t = Trame.Trame([str(self.ia_id), "log", "player", "", "", data])
        self.bot.sockets_output_buffer["tcp"].append(t.serialize())

    def throwBomb(self, direction, strength):
        print("[ACTION]: throw bomb")
        if True:#len(self.bombs) > 0:
            new_dir = (math.cos(direction), math.sin(direction))
            #b = self.bombs.pop()
            data = str(float(new_dir[0])) + "|" + str(float(new_dir[1])) + "|" + str(float(self.dir[2])) + "|" + str(int(strength))
            t = Trame.Trame([str(self.ia_id), "throw_bomb", "player", "", str(self.ia_id), data])
            self.bot.sockets_output_buffer["tcp"].append(t.serialize())
        else:
            print("[ERROR]: not enough bombs")

    def addTimer(self, name, action_type, timeout, callback, args):
        self.log("[INFO]: add timer [" + str(name) + "] type [" + str(action_type) + "] during [" + str(timeout) + "]");
        self.core.timers.addTimer(name, action_type, timeout, callback, args)

    def deleteTimer(self, name):
        try:
            self.ore.timers.delTimer(name)
            self.log("[INFO]: remove timer " + str(name))
        except IndexError:
            print("[ERROR]: unknow timer " + name)

    def getTimeout(self, name):
        try:
            return (self.core.timers.getTimeout(name))
        except IndexError:
            print("[ERROR]: unknow timer " + name)
            return (None)

    def inExplosion(self, pos, radius):
        for i in self.core.map.bomb:
            npos = i.getComponent("position")
            nex = i.getComponent("explose")
            x = npos.x
            y = npos.y
            r = nex.strength
            d = math.fabs((x - pos[0])**2 + (y - pos[1])**2)
            if d < (r + radius)**2:
                self.log("[INFO]: i am in explosion [" + str(pos[0]) + "] [" + str(pos[1]) + "] in this radius " + str(radius))
                return (True)
        return (False)

    def timeBeforeExplosion(self, pos, radius):
        timerbomb = []
        for i in self.core.map.bomb:
            try:
                npos = i.getComponent("position")
                nex = i.getComponent("explose")
            except IndexError:
                print("[Error]: missing component")
            else:
                x = npos.x
                y = npos.y
                r = nex.strength
                d = math.fabs((x - pos[0])**2 + (y - pos[1])**2)
                if d < (r + radius)**2:
                    timerbomb.append(self.core.timer.get("bomb:" + str(i.id)))
        if len(timerbomb) > 0:
            self.log("[INFO]: time before explosion = " + min(timerbomb))
            return (min(timerbomb))
        return (None)

    def storeData(self, name, value):
        self.log("[INFO]: storing " + str(name) + " with value " + str(value))
        self.core.storage[name] = value

    def getData(self, name):
        try:
            self.log("[INFO]: get data from " + str(name) + " = " + str(self.core.storage[name]))
            return (self.core.storage[name])
        except KeyError:
            print("[Error]: no key " + name + " in storage container")
            return (None)
