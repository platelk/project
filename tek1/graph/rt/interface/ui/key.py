#!/usr/bin/python2.7
#
#by ozouf_h

from camera import *
from objects import *
from scene import *
from copy import *

class   Key_img:
    def __init__(self, camera, nbr_frame):
        self.camera = camera
        self.nbr_frame = nbr_frame

    def interpol_cam(self, ref_cam):
        if (self.nbr_frame == 0):
            return (1)
        it_px = (ref_cam.pos.x - self.camera.pos.x) / self.nbr_frame
        it_py = (ref_cam.pos.y - self.camera.pos.y) / self.nbr_frame
        it_pz = (ref_cam.pos.z - self.camera.pos.z) / self.nbr_frame
        it_rx = (ref_cam.rot.x - self.camera.rot.x) / self.nbr_frame
        it_ry = (ref_cam.rot.y - self.camera.rot.y) / self.nbr_frame
        it_rz = (ref_cam.rot.z - self.camera.rot.z) / self.nbr_frame
        self.nbr_frame -= 1
        ref_cam.pos.x += it_px
        ref_cam.pos.y += it_py
        ref_cam.pos.z += it_pz
        ref_cam.rot.x += it_rx
        ref_cam.rot.y += it_ry
        ref_cam.rot.z += it_rz

        self.px.append(self.new.pos.x.text())
        self.py.append(self.new.pos.y.text())
        self.pz.append(self.new.pos.z.text())
        self.rx.append(self.new.rot.x.text())
        self.ry.append(self.new.rot.y.text())
        self.rz.append(self.new.rot.z.text())

        it_px = float(float(self.px[i] - self.px[i + 1]) / float(nbr_frame))
        it_py = float(float(self.py[i] - self.py[i + 1]) / float(nbr_frame))
        it_pz = float(float(self.pz[i] - self.pz[i + 1]) / float(nbr_frame))
        it_rx = float(float((self.rx[i] - self.rx[i + 1])) / float(nbr_frame))
        it_ry = float(float(self.ry[i] - self.ry[i + 1]) / float(nbr_frame))
        it_rz = float(float(self.rz[i] - self.rz[i + 1]) / float(nbr_frame))

class   keys:
    def __init__(self, scene):
        self.reference = scene
        self.nbr_frame = 0
        self.prev_img = scene
        self.actual_key = 0
        self.keys = list()

    def add(self, scene_key):
        self.keys.append((scene_key))

    def calc_next_key(self, f):
        while (self.keys[self.actual_key].nbr_frame > 0):
            self.keys[self.actual_key].interpol_cam(self.prev_img)
            new_cam = self.keys[self.actual_frame].camera
            new_objects = self.prev_img.objects
            new_light = self.prev_img.lights
            new_name = self.prev_img.name
            new_aa = self.prev_img.aa
            self.prev_img = Scene(new_cam, new_objects, new_light, new_name, new_aa)
            self.prev_img.write_in_file(f)
        self.actual_key += 1
