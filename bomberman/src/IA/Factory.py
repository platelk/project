#! /bin/python3.3

import  math
from Trame import Trame

class   GameObject:
    def __init__(self, name, id):
        self.name = name
        self.id = id
        self.component = []

    def haveThisComponent(self, name):
        for i in self.component:
            if i.name == name:
                return (True)
        return (False)

    def getComponent(self, name):
        for i in self.component:
            if i.name == name:
                return (i)
        raise IndexError("cant find this component")

    def clone(self):
        return (GameObject(self.name, self.id))

    def aff(self):
        print("gameobjet of type " + self.name + " and unique id = " + str(self.id))
        for i in self.component:
            i.aff()
        
class   Component:
    def __init__(self, name):
        self.name = name

class   CPlife(Component):
    def __init__(self, l, m):
        Component.__init__(self, "life")
        self.life = l
        self.max = m

    def clone(self):
        return (CPlife(self.life, self.max))

    def addAttr(self, li):
        if len(li) == 2 and type(li[0]) == int and type(li[1]) == int:
            self.life = li[0]
            self.max = li[1]
        else:
            raise SyntaxError("too much argument for create a Component")

    def aff(self):
        print("component [LIFE] with: life = " + str(self.life))


class   CPmove(Component):
    def __init__(self, speed):
        Component.__init__(self, "move")
        self.speed = speed

    def clone(self):
        return (CPmove(self.speed))

    def addAttr(self, li):
        if len(li) != 1:
            raise SyntaxError("too much argument for create a Component")
        self.speed = li[0]
        

    def aff(self):
        print("component [MOVE]")


class   CPposition(Component):
    def __init__(self, x, y, z, dx, dy, dz):
        Component.__init__(self, "position")
        self.x = x
        self.y = y
        self.z = z
        self.dx = dx
        self.dy = dy
        self.dz = dz
        
    def clone(self):
        return (CPposition(self.x, self.y, self.z, self.dx, self.dy, self.dz))

    def addAttr(self, li):
        if len(li) == 6 and type(li[0]) == float and type(li[1]) == float and \
                type(li[2]) == float and type(li[3]) == float and type(li[4]) == float \
                and type(li[5]) == float:
            self.x = li[0]
            self.y = li[1]
            self.z = li[2]
            self.dx = li[3]
            self.dy = li[4]
            self.dz = li[5]
        else:
            raise SyntaxError("too much argument for create a Component")
        
    def aff(self):
        print("component [POSITION]", self.x, self.y, self.z, self.dx, self.dy, self.dz)

class   CPcollider(Component):
    def __init__(self):
        Component.__init__(self, "colider")
        self.circle = []

    def clone(self):
        return (CPcollider())
    
    def addAttr(self, li):
        i = 0
        try:
            while i < len(li):
                if type(li[i]) == int and type(li[i + 1]) == int and \
                        type(li[i + 2]) == int and type(li[i + 3]) == int:
                    self.circle.append((li[i], li[i + 1], li[i + 2], li[i + 3]))
                else:
                    raise SyntaxError("bad type")
                i += 4
        except (SyntaxError, LookupError, ValueError, IndexError):
            raise SyntaxError("missing argument or bad type")

    def collide(self, obj_pos, pos, radius):
        for i in self.circle:
            x = obj_pos[0] + i[0]
            y = obj_pos[1] + i[1]
            r = i[3]
            d = math.fabs((x - pos[0])**2 + (y - pos[1])**2)
            if d < (r + radius)**2:
                return True
        return (False)

    def aff(self):
        print("component [COLLIDER] with ", len(self.circle), "circles")

class   CPexplose(Component):
    def __init__(self, timeout, strength, effect):
        Component.__init__(self, "explose")
        self.timeout = timeout
        self.strength = strength
        self.effect = effect
        
    def clone(self):
        return (CPexplose(self.timeout, self.strength, self.effect))
    
    def addAttr(self, li):
        if len(li) == 3 and type(li[0]) == float and \
                type(li[1]) == int and type(li[2]) == str:
            self.timeout = li[0]
            self.strength = li[1]
            self.effect = li[2]
        else:
            raise SyntaxError("too much argument for create a Component")

    def aff(self):
        print("component [EXPOLSE] with ", self.timeout, self.strength, self.effect)

class   CPthrow_bomb(Component):
    def __init__(self):
        Component.__init__(self, "throw_bomb")
        self.recovery = 0
    
    def clone(self):
        return (CPthrow_bomb())
    
    def addAttr(self, li):
        if len(li) == 1:
            self.recovery = li[0]
        else:
            raise SyntaxError("too much argument for create a Component")

    def aff(self):
        print("component [throw_bomb] with ", "noting")



class   Factory:
    def __init__(self):
        self.obj = {}
        self.component = {}
        self.obj["player"] = GameObject("player", 0)
        self.obj["item"] = GameObject("item", 0)
        self.obj["decor"] = GameObject("decor", 0)
        self.component["life"] = CPlife(100, 100)
        self.component["move"] = CPmove(5)
        self.component["position"] = CPposition(0, 0, 0, 0, 0, 0)
        self.component["explose"] = CPexplose(0.0, 0, "nothing")
        self.component["colider"] = CPcollider()
        self.component["throw_bomb"] = CPthrow_bomb()

    def __match_name(self, t, name):
        if t == "GameObject":
            for i in self.obj:
                if name == i:
                    return (self.obj[name].clone())
            return (None)
        elif t == "Component":
            for i in self.component:
                if name == i:
                    return (self.component[name].clone())
            return (None)
        else:
            raise NameError("unknow " + t)
        
    def __disperse_type(self, decode):#checker type avant insert
        created = []
        for obj in decode:
            if obj[0] == "GameObject":
                res = self.__match_name("GameObject", obj[1][0])
                if res != None:
                    res.id = int(obj[1][1])
                    content = self.__disperse_type(obj[1][2])
                    for elms in content:
                        res.component.append(elms)
                    created.append(res)
            elif obj[0] == "Component":
                res = self.__match_name("Component", obj[1][0])
                if res != None:
                    res.addAttr(self.__disperse_type(obj[1][1]))
                    created.append(res)
            elif obj[0] == None:
                created.append(obj[1])
            else:
                raise NameError("unknow type name")
        return (created)

    def create(self, data):
        res = []
        decode, trame_pos = Trame.unserializeObject(data)
        obj = self.__disperse_type(decode)
        if len(obj) == 0:
            return (None)
        return (obj[0])
