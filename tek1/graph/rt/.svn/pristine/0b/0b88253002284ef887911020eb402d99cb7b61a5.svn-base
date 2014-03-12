 #!/usr/bin/python2.7

#by ozouf_h
######################

from xml.dom import minidom
from objects import *
from scene import *

class   Engine:
    def __init__(self):
        self.g = 1.0

    def update(self, scene, path):
        for o in scene.objects:
            if (isinstance(o, Sphere)):
                o.move(self, scene)
        scene.write_in_file(path)
