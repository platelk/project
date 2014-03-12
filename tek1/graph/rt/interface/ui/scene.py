#!/usr/bin/python2.7
#
#by ozouf_h

############################
import sys
from objects import *
from camera import *
from engine_physic import *
from xml.dom import minidom
from xml.dom.minidom import parse

class   Scene:
    def __init__(self, camera=None, objects=None, lights=None, name="42", aa=0):
        self.name = name
        self.aa = aa
        self.camera = camera
        self.objects = objects
        self.lights = lights

    def write_in_file(self, f):
        prolog = "<scene name=\"" + self.name + "\" antialiasing=\"" + self.aa + "\">\n"
        camera = "<cameras>\n<camera>\n<location X=\"" + str(self.camera.pos.x) + "\" Y=\"" + str(self.camera.pos.y) + "\" Z=\"" + str(self.camera.pos.z) + "\"/>\n<rotation X=\"" +  str(self.camera.rot.x) + "\" Y=\"" + str(self.camera.rot.y) + "\" Z=\"" + str(self.camera.rot.z) + "\"/>\n<fov>" + str(self.camera.fov) + "</fov>\n</camera>\n</cameras>\n"
        f.write(prolog)
        f.write(camera)
        f.write(self.objects)
        f.write("\n")
        f.write(self.lights)
        f.write("\n</scene>\n")

class   Parsing:
    def __init__(self, path):
        print path
        self.dom = parse(path)

    def parse_camera(self):
        try:
            camera = self.dom.getElementsByTagName("camera")
            p = camera[0].getElementsByTagName("location")
            p = Postion(float(p[0].getAttribute('X')), float(p[0].getAttribute('Y')), float(p[0].getAttribute('Z')))
            r = camera[0].getElementsByTagName("rotation")
            r = Postion(float(r[0].getAttribute('X')), float(r[0].getAttribute('Y')), float(r[0].getAttribute('Z')))
            fov = float(camera[0].getElementsByTagName("fov")[0].childNodes[0].nodeValue)
            return (Camera(p, r, fov))
        except:
            return (Camera(Postion(0, 0, 0), Postion(0, 0, 0), 1000))

    def parse_objects(self):
        return (self.dom.getElementsByTagName("object")[0].toxml())

    def parse_lights(self):
        return (self.dom.getElementsByTagName("lights")[0].toxml())

    def parse_scene(self):
        obj = self.parse_objects()
        lig = self.parse_lights()
        cam = self.parse_camera()
        aa = self.dom.getElementsByTagName("scene")[0].getAttribute("antialiasing")
        name = self.dom.getElementsByTagName("scene")[0].getAttribute("name")
        return (Scene(cam, obj, lig, name, aa))
