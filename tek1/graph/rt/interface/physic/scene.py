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
        objects = "<object>\n"
        for o in self.objects:
            objects += o.to_txt()
        objects += "</object>\n"
        f.write(prolog)
        f.write(camera)
        f.write(objects)
        f.write(self.lights)
        f.write("\n</scene>\n")

class   Parsing:
    def __init__(self, path):
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
        objects = self.dom.getElementsByTagName("object")
        o = []
        for sphere in objects[0].getElementsByTagName("sphere"):
            p = sphere.getElementsByTagName("location")
            p = Postion(float(p[0].getAttribute('X')), float(p[0].getAttribute('Y')), float(p[0].getAttribute('Z')))
            r = sphere.getElementsByTagName("rotation")
            r = Postion(float(r[0].getAttribute('X')), float(r[0].getAttribute('Y')), float(r[0].getAttribute('Z')))
            effect = sphere.getElementsByTagName("effect")[0].toxml()
            c = sphere.getElementsByTagName("color")[0].childNodes[0].nodeValue
            radius = float(sphere.getElementsByTagName("radius")[0].childNodes[0].nodeValue)
            o.insert(0, Sphere(p, r, c, radius, effect))
        for plan in objects[0].getElementsByTagName("plan"):
            p = plan.getElementsByTagName("location")
            p = float(Postion(p[0].getAttribute('X')), float(p[0].getAttribute('Y')), float(p[0].getAttribute('Z')))
            r = plan.getElementsByTagName("rotation")
            r = Postion(float(r[0].getAttribute('X')), float(r[0].getAttribute('Y')), float(r[0].getAttribute('Z')))
            effect = plan.getElementsByTagName("effect")
            c = plan.getElementsByTagName("color")[0].childNodes[0].nodeValue
            o.insert(0, Plan(p, r, c, effect))
        for other in objects[0].getElementsByTagName("cylinder"):
            o.insert(0, Ingore_obj(other.toxml()))
        for other in objects[0].getElementsByTagName("cone"):
            o.insert(0, Ingore_obj(other.toxml()))
        for other in objects[0].getElementsByTagName("tore"):
            o.insert(0, Ingore_obj(other.toxml()))
        for other in objects[0].getElementsByTagName("cubetroue"):
            o.insert(0, Ingore_obj(other.toxml()))
        return (o)

    def parse_lights(self):
        return (self.dom.getElementsByTagName("lights")[0].toxml())

    def parse_scene(self):
        obj = self.parse_objects()
        lig = self.parse_lights()
        cam = self.parse_camera()
        aa = self.dom.getElementsByTagName("scene")[0].getAttribute("antialiasing")
        name = self.dom.getElementsByTagName("scene")[0].getAttribute("name")
        return (Scene(cam, obj, lig, name, aa))

def     main():
    f = Parsing("./toto.xml")
    scene = f.parse_scene()
    engine = Engine()
    i = 0
    f = open("./res.xml", "w")
    f.write("<window y=\"800\" x=\"800\">\n")
    while (i < 5):
        print "iteration n`" + str(i)
        engine.update(scene, f)
        i += 1
    f.write("</window>")
    f.close()

if __name__ == '__main__':
    main()
