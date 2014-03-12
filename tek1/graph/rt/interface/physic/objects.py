#!/usr/bin/python2.7
#
#by ozouf_h

############################

import math

class   Postion:
    def __init__(self, x=0, y=0, z=0):
        self.x = x
        self.y = y
        self.z = z

    def print_it(self):
        print self.x
        print self.y
        print self.z

    def dist_eucl(self, other):
        cx = math.pow(other.x - self.x, 2)
        cy = math.pow(other.y - self.y, 2)
        cz = math.pow(other.z - self.z, 2)
        print "euclid " + str(cx) + " " + str(cy) + " " +  str(cz) + " " + str(cx + cy + cz) + " " + str(math.sqrt(cx + cy + cz)) + " " + str(math.fabs(math.sqrt(cx + cy + cz)))
        return (math.fabs(math.sqrt(cx + cy + cz)))

############################

class   Color:
    def __init__(self, r=0, g=0, b=0):
        self.r = r
        self.g = g
        self.b = b

#############################

class   Vector(Postion):
    def __init__(self, x=0, y=0, z=0):
        super(Vector, self).__init__(x, y, z)

    def __add__(self, vec):
        return (Vector(self.x + vec.x, self.y + vec.y, self.z + vec.z))

    def __sub__(self, vec):
        if (isinstance(n,Vector)):
            return (Vector(self.x - vec.x, self.y - vec.y, self.z - vec.z))
        return (Vect(self.x - vec, self.y - vec, self.z - vec))

    def __mul__(self, n):
        if (isinstance(n,Vector)):
            return (self.x * n.x + self.y * n.y + self.x * n.z)
        return (Vector(self.x * n, self.y * n, self.z * n))

    def __abs__(self):
        return (math.sqrt(self.x * self.x + self.y * self.y + self.z * self.z))

    def scalaire(self, other):
        return (self.x * other.x + self.y * other.y + self.z * other.z)

############################

class   Object(object):
    def __init__(self, pos=None, rot=None, color="000000", effect=None):
        self.pos = pos
        self.rot = rot
        self.vel = Postion(0, 0, 0)
        self.acc = Postion(0, 0, 0)
        self.m = 20
        self.color = color
        self.effect = effect
        self.type = "normal"

    def check_collide(self, scene):
        for o in scene.objects:
            if (isinstance(o, Sphere)):
                if (o != self):
                    dist = self.pos.dist_eucl(o.pos)
                    print str(dist)
                    if (self.r + o.r >= dist):
                        print "collision " + str(self.r + o.r) + "d = " + str(dist)
                        it = o.inter(self.pos, o.pos)
                        if (it != None):
                            normal = Vector(it.x - o.pos.x, it.y - o.pos.y, it.z - o.pos.z)
                            self.vel = self.vel - 2 * self.vel.scalaire(normal) * normal

    def change_pos(self, engine):
        self.pos.x -= self.vel.x
        self.pos.y -= self.vel.y
        self.pos.z -= self.vel.z
        self.vel.z += engine.g
        print "x = " + str(self.pos.x) + " y = " + str(self.pos.y) + " z = " + str(self.pos.z)
    def move(self, engine, scene):
        self.change_pos(engine)
        self.check_collide(scene)

#############################

class   Ingore_obj:
    def __init__(self, txt):
        self.content = txt

    def to_txt(self):
        return (self.content.toxml())

#############################

class   Sphere(Object):
    def __init__(self, pos=None, rot=None, color=None, radius=10, effect=None):
        super(Sphere, self).__init__(pos, rot, color, effect)
        self.r = radius

    def s_radius(self, radius=10):
        self.r = radius

    def to_txt(self):
        txt = "<sphere type=\"" + self.type + "\">\n"
        txt += "<location X=\"" + str(self.pos.x) + "\" Y=\"" + str(self.pos.y) + "\" Z=\"" + str(self.pos.z) + "\"/>\n"
        txt += "<rotation X=\"" + str(self.rot.x) + "\" Y=\"" + str(self.rot.y) + "\" Z=\"" + str(self.rot.z) + "\"/>\n"
        if (self.effect != None):
            txt += self.effect + "\n"
        txt += "<color>" + self.color +"</color>\n"
        txt += "<radius>" + str(self.r) + "</radius>\n"
        txt += "</sphere>\n"
        return (txt)

    def inter(self, A, B):
        dpos = Postion(B.x - A.x, B.y - A.y, B.z - A.z)
        dc = Postion(A.x - self.pos.x, A.y - self.pos.y, A.z - self.pos.z)
        a = math.pow(dpos.x, 2) + math.pow(dpos.y, 2) + math.pow(dpos.z, 2)
        b = 2 * (dpos.x * dc.x + dpos.y * dc.y + dpos.z * dc.z)
        c = math.pow(self.pos.x, 2) + math.pow(self.pos.y, 2) + math.pow(self.pos.z, 2) + math.pow(A.x, 2) + math.pow(A.y, 2) + math.pow(A.z, 2) - 2 * (A.x * self.pos.x + A.y * self.pos.y + A.z * self.pos.z) - math.pow(self.r, 2)
        delta = b * b - 4 * a * c
        if (delta > 0):
            x1 = (-b + math.sqrt(delta)) / 2 * a
            x2 = (-b - math.sqrt(delta)) / 2 * a
            a = []
            k1 = Position(x1 * dpos.x + A.x, x1 * dpos.y + A.y, x1 * dpos.z + A.z)
            k2 = Position(x2 * dpos.x + A.x, x2 * dpos.y + A.y, x2 * dpos.z + A.z)
            if (x1 < x2):
                return (k1)
            return (k2)
        else:
            return (None)

#############################

class   Plan(Object):
    def __init__(self, pos=None, rot=None, c=None, effect=None):
        super(Plan, self).__init__(pos, rot, c, effect)

    def to_txt(self):
        txt = "<plan type=\"" + self.type + "\">\n"
        txt += "<location X=\"" + self.pos.x + "\" Y=\"" + self.pos.y + "\" Z=\"" + self.pos.z + "\"/>\n"
        txt += "<rotation X=\"" + self.rot.x + "\" Y=\"" + self.rot.y + "\" Z=\"" + self.rot.z + "\"/>\n"
        if (self.effect != None):
            txt += self.effect + "\n"
        txt += "<color>" + self.color +"</color>\n"
        txt += "</plan>\n"
