#!/usr/bin/python2.7
#
#by ozouf_h

from sub_ui import *
from scene import *
from key import *
from objects import *

try:
    from PyQt4.QtCore import *  # Moteur controle Qt
    from PyQt4.QtGui import *   # IHM Qt
except:
    import time                 # Gestion heures systeme
    for i in range(1, 11):
        print ("PyQt is not install - check in (%d/10)", i)
        time.sleep(5)
        sys.exit(1)

class   Ui_edit_movie(QDialog):
    def __init__(self, Window=None, path="./toto.xml"):
        super(Ui_edit_movie, self).__init__(Window)
        self.px = list()
        self.py = list()
        self.pz = list()
        self.rx = list()
        self.ry = list()
        self.rz = list()
        self.nbr_frame = 20
        self.lFrame = list()

    def init(self, Window=None, path="./toto.xml", s=None):
        self.k = list()
        self.Path = path
        self.S = s
        self.GridLay = QGridLayout(self)
        self.Coor = QGroupBox("Key images", self)
        hLayout = QHBoxLayout(self)
        self.Parent = Window
        act = QPushButton("Add key", self)
        act.connect(act, SIGNAL("clicked()"), self.add_elm)
        hLayout.addWidget(act)
        act = QPushButton("Quit", self)
        act.connect(act, SIGNAL("clicked()"), self.reject)
        hLayout.addWidget(act)
        self.item = QListWidget()
        f = Parsing(path)
        self.i = 0
        self.scene = f.parse_scene()
        self.keys = keys(self.scene)
        self.edit_scene = self.scene
        self.s_pos = self.scene.camera.pos
        self.s_rot = self.scene.camera.rot
        self.GridLay.addWidget(self.item, 0, 0)
        self.Coor.setLayout(hLayout)
        self.GridLay.addWidget(self.Coor, 1, 0)
        hLayout = QHBoxLayout(self)
        act = QPushButton("Generate")
        act.connect(act, SIGNAL("clicked()"), self.Generate)
        hLayout.addWidget(act)
        act = QPushButton("Cancel")
        act.connect(act, SIGNAL("clicked()"), self.quit)
        hLayout.addWidget(act)
        self.GridLay.addLayout(hLayout, 5, 0)
        self.show()

    def add_elm(self, Window=None):
        self.new = QDialog(self)
        self.new.pos = Coor(self.new, x=str(self.s_pos.x), y=str(self.s_pos.y), z=str(self.s_pos.z), Prev=False)
        self.new.rot = Coor(self.new, x=str(self.s_rot.x), y=str(self.s_rot.y), z=str(self.s_rot.z), Prev=False)
        self.new.GridLayout = QGridLayout(self.new)

        self.new.Coor = QGroupBox("Rotation", self.new)
        hLayout = QHBoxLayout(self)

        hLayout.addWidget(self.new.rot.Lab_x)
        hLayout.addWidget(self.new.rot.x)
        hLayout.addWidget(self.new.rot.Lab_y)
        hLayout.addWidget(self.new.rot.y)
        hLayout.addWidget(self.new.rot.Lab_z)
        hLayout.addWidget(self.new.rot.z)

        self.new.Coor.setLayout(hLayout)
        self.new.GridLayout.addWidget(self.new.Coor, 1, 0)

        self.new.Coor = QGroupBox("Position", self.new)
        hLayout = QHBoxLayout(self.new)

        hLayout.addWidget(self.new.pos.Lab_x)
        hLayout.addWidget(self.new.pos.x)
        hLayout.addWidget(self.new.pos.Lab_y)
        hLayout.addWidget(self.new.pos.y)
        hLayout.addWidget(self.new.pos.Lab_z)
        hLayout.addWidget(self.new.pos.z)

        self.new.Coor.setLayout(hLayout)
        self.new.GridLayout.addWidget(self.new.Coor, 2, 0)


        hLayout = QHBoxLayout(self.new)
        hLayout.addWidget(QLabel("Frame Rate :"))
        self.labFrame = QLineEdit("20")
        hLayout.addWidget(self.labFrame)
        self.new.GridLayout.addLayout(hLayout, 3, 0)

        hLayout = QHBoxLayout(self.new)
        act = QPushButton("Ok", self.new)
        act.connect(act, SIGNAL("clicked()"), self.create_new_key)
        hLayout.addWidget(act)
        act = QPushButton("Cancel", self.new)
        act.connect(act, SIGNAL("clicked()"), self.new.reject)
        hLayout.addWidget(act)

        self.new.GridLayout.addLayout(hLayout, 10, 0)
        self.new.show()

    def quit(self):
        if (self.Parent):
            self.Parent.setEnabled(True)
        self.reject()

    def create_new_key(self):
        self.px.append(self.new.pos.x.text())
        self.py.append(self.new.pos.y.text())
        self.pz.append(self.new.pos.z.text())
        self.rx.append(self.new.rot.x.text())
        self.ry.append(self.new.rot.y.text())
        self.rz.append(self.new.rot.z.text())
        try:
            self.lFrame.append(float(self.labFrame))
        except:
            self.lFrame.append(20.0)

        self.edit_scene.camera.rot = Postion(float(str(self.rx[-1])), float(str(self.ry[-1])), float(str(self.rz[-1])))
        self.s_pos = Postion(float(str(self.px[-1])), float(str(self.py[-1])), float(str(self.pz[-1])))
        self.s_rot = Postion(float(str(self.rx[-1])), float(str(self.ry[-1])), float(str(self.rz[-1])))
        self.item.addItem("Key Image n" + str(self.i))
        new_cam = self.edit_scene.camera
        new_objects = self.edit_scene.objects
        new_light = self.edit_scene.lights
        new_name = self.edit_scene.name
        new_aa = self.edit_scene.aa
        self.edit_scene = Scene(new_cam, new_objects, new_light, new_name, new_aa)
        self.k.append(self.edit_scene)
        self.i += 1
        self.new.accept()


    def Generate(self):
        print "Generation..."
        f = file(self.Path, 'w')
        f.write(self.S)
        i = 0
        while ((i + 1) < len(self.k)):
            print i
            new = self.k[i + 1].camera
            try:
                nbr_frame = float(self.labFrame.displayText())
            except:
                nbr_frame = self.lFrame(i)
            ref_cam = self.k[i].camera
            print ("Ref pos x = " + str(ref_cam.pos.x))
            print ("New pos x = " + str(new.pos.x))
            print ("Frame = " + str(nbr_frame))
            it_px = (float(self.px[i]) - float(self.px[i+1])) / float(nbr_frame)
            it_py = (float(self.py[i]) - float(self.py[i+1])) / float(nbr_frame)
            it_pz = (float(self.pz[i]) - float(self.pz[i+1])) / float(nbr_frame)
            it_rx = (float(self.rx[i]) - float(self.rx[i+1])) / float(nbr_frame)
            it_ry = (float(self.ry[i]) - float(self.ry[i+1])) / float(nbr_frame)
            it_rz = (float(self.rz[i]) - float(self.rz[i+1])) / float(nbr_frame)
            print ("it = " + str(it_px))
            while (nbr_frame > 0):
                        nbr_frame -= 1
                        ref_cam.pos.x += it_px
                        ref_cam.pos.y += it_py
                        ref_cam.pos.z += it_pz
                        ref_cam.rot.x += it_rx
                        ref_cam.rot.y += it_ry
                        ref_cam.rot.z += it_rz
                        c = self.k[i]
                        c.camera = ref_cam
                        c.write_in_file(f)
            i += 1
        f.write("</window>")
        f.close()

if __name__ == '__main__':
    new = Ui_edit_movie()
