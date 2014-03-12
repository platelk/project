#!/usr/bin/python2.7

import sys
from xml.dom import *
import xml.parsers.expat

########################
class   Object:
    def __init__(x=0, y=0 , z=0, r_x=0, r_y=0, r_z=0, color=0):
        self.pos = list(x, y, z)
        self.rot = list(r_x, r_y, r_z)
        self.Txt = None
        self.color = color
        self.Name = None

    def setPos(i, value=0):
        if (i < len(self.pos) and i > 0):
            self.pos[i] = value

    def setRot(i, value=0):
        if (i < len(self.rot) and i > 0):
            self.rot[i] = value

    def setColor(value=0):
        self.color = value

    def setText(self, string):
        self.Txt = string

    def setName(self, name):
        self.Name = name

########################

class   Light(Object):
    def __init__(x=0, y=0 , z=0, r_x=0, r_y=0, r_z=0, color=0, intensity=0.0):
        super(Light, self).__init__(x, y, z, r_x, r_y, r_z, color)
        self.intensity = intensity

###########

class   Cam(Object):
    def __init__(fov=500, x=0, y=0 , z=0, r_x=0, r_y=0, r_z=0, color=0):
        super(Cam, self).__init__(x, y, z, r_x, r_y, r_z, color)
        self.fov = fov

########################

class   Shape(Object):
    def __init__(x=0, y=0 , z=0, r_x=0, r_y=0, r_z=0, color=0, effect = None, t=0):
        super(Shape, self).__init__(x, y, z, r_x, r_y, r_z, color)
        self.effect = effect
        self.type = t

class   Sphere(Shape):
    def __init__(x=0, y=0 , z=0, r_x=0, r_y=0, r_z=0, color=0, effect = None, r=0, t=0):
        super(Sphere, self).__init__(x, y, z, r_x, r_y, r_z, color)
        self.R = r
    def setRayon(value):
        self.R = value

class   Cone(Shape):
    def __init__(x=0, y=0 , z=0, r_x=0, r_y=0, r_z=0, color=0, effect = None, r=0, t=0):
        super(Cone, self).__init__(x, y, z, r_x, r_y, r_z, color)
        self.R = r
    def setRayon(value):
        self.R = value

class   Cylindre(Shape):
    def __init__(x=0, y=0 , z=0, r_x=0, r_y=0, r_z=0, color=0, effect = None, r=0, t=0):
        super(Cylindre, self).__init__(x, y, z, r_x, r_y, r_z, color)
        self.R = r
    def setRayon(value):
        self.R = value

class   Plan(Shape):
    def __init__(x=0, y=0 , z=0, r_x=0, r_y=0, r_z=0, color=0, effect = None, t=0):
        super(Plan, self).__init__(x, y, z, r_x, r_y, r_z, color)

########################

class   Scene:
    def __init__(obj = None, light = None, cam = None):
        self.object = obj
        self.light = light
        self.cam = cam

class   Window:

    def __init__(name=None, win_x=500, win_y=500):
        self.win_x = win_x
        self.win_y = win_y
        self.scene = Scene()
        self.Name = "window"

def     main():

    from xml.dom.minidom import parse
    doc = parse("./test.xml")
    for personnes in doc.documentElement.getElementsByTagName("window"):
        if personnes.nodeType == personnes.ELEMENT_NODE:
            try:
                print (personnes.getElementsByTagName("nom")[0])
                print (personnes.getElementsByTagName("prenom")[0])
                print (personnes.getElementsByTagName("adresse")[0])
            except:
                print ('Un des TAGS suivant est manquents : nom, prenom, adresse')
            self.__personneList__.append(p)
        return self.__personneList__

if __name__ == '__main__':
    main()
