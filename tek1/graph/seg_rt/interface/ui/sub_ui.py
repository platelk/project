#!/usr/bin/python2.7

from ui import *
from obj import *
import sys

try:
    from PyQt4.QtCore import *  # Moteur controle Qt
    from PyQt4.QtGui import *   # IHM Qt
except:
    import time                 # Gestion heures systeme
    for i in range(1, 11):
        print ("PyQt is not install - check in (%d/10)", i)
        time.sleep(5)
        sys.exit(1)

import ui

class uiDialog(QDialog):
    def __init__(self, Window=None, winFlag=0):
        super(uiDialog, self).__init__(Window)

class Coor:
    def __init__(self, Window, Layout=None, one="X :", sec="Y :", third="Z :"
                 , x="0", y="0", z="0"):
        self.x = None
        self.Lab_x = None

        self.y = None
        self.Lab_y = None

        self.z = None
        self.Lab_z = None

        if (one):
            self.x = QLineEdit(x, Window)
            self.x.connect(self.x, SIGNAL("editingFinished()"), Window.setPrev)
            self.Lab_x = QLabel(one, Window)

        if (sec):
            self.y = QLineEdit(y, Window)
            self.y.connect(self.y, SIGNAL("editingFinished()"), Window.setPrev)
            self.Lab_y = QLabel(sec, Window)

        if (third):
            self.z = QLineEdit(z, Window)
            self.z.connect(self.z, SIGNAL("editingFinished()"), Window.setPrev)
            self.Lab_z = QLabel(third, Window)

    def getText(self, Name, first="X=\"", sec="Y=\"", third="Z=\""):
        x = "<" + Name + " "
        if (first and self.x):
            x = x + first + self.x.displayText() + "\" "
        if (sec and self.y):
            x = x + sec + self.y.displayText() + "\" "
        if (third and self.z):
            x = x + third + self.z.displayText() + "\" "
        x = x + "/>"
        return (x)

class effect:
    def __init__(self, Window):
        self.Brightness = QSlider(0x1, Window)
        self.labBrightness = QLabel("Brightness", Window)
        self.Brightness.setMaximum(100)
        self.Brightness.setMinimum(0)
        self.Brightness.connect(self.Brightness, SIGNAL("sliderReleased()"), Window.setPrev)
        self.Reflection = QSlider(0x1, Window)
        self.labReflection = QLabel("Reflection", Window)
        self.Reflection.setMaximum(100)
        self.Reflection.setMinimum(0)
        self.Reflection.connect(self.Reflection, SIGNAL("sliderReleased()"), Window.setPrev)

    def getText(self):
        r = "<effect BRIGHTNESS=\"" + str(float(self.Brightness.sliderPosition()) / 100.0) + "\" REFLECTION=\"" + str(float(self.Reflection.sliderPosition()) / 100.0) + "\" />"
        return (r)

class uiAddObject(uiDialog):

    def __init__(self, Window=None, winFlag=0, obj=None, s=None,
                 px="0", py="0", pz="0",
                 rx="0", ry="0", rz="0",
                 tx="0", ty="0", tz="0",
                 color="000000", template=None):
        super(uiAddObject, self).__init__(Window)
        self.Parent = Window
        self.Obj = obj
        self.str = s
        self.color = color
        self.link = template
        if (self.link):
            self.tem = self.link
        else:
            self.tem = "/"
        self.per = None
        self.effect = None
        self.isNeg = None
        self.pos = Coor(self, x=px, y=py, z=pz)
        self.rot = Coor(self, x=rx, y=ry, z=rz)
        if (obj != "camera" and obj != "light"):
            self.per = Coor(self, x=tx, y=ty, z=tz)
        self.setWindowTitle("New " + self.Obj)

    def init(self, obj):
        self.GridLay = QGridLayout(self)
        self.Coor = QGroupBox("Position", self)
        vLayout = QVBoxLayout(self)
        hLayout = QHBoxLayout(self)


        hLayout.addWidget(self.pos.Lab_x)
        hLayout.addWidget(self.pos.x)
        hLayout.addWidget(self.pos.Lab_y)
        hLayout.addWidget(self.pos.y)
        hLayout.addWidget(self.pos.Lab_z)
        hLayout.addWidget(self.pos.z)

        self.Coor.setLayout(hLayout)
        vLayout.addWidget(self.Coor)
#        self.GridLay.addWidget(self.Coor, 0, 1)

        self.Coor = QGroupBox("Rotation", self)
        hLayout = QHBoxLayout(self)

        hLayout.addWidget(self.rot.Lab_x)
        hLayout.addWidget(self.rot.x)
        hLayout.addWidget(self.rot.Lab_y)
        hLayout.addWidget(self.rot.y)
        hLayout.addWidget(self.rot.Lab_z)
        hLayout.addWidget(self.rot.z)

        self.Coor.setLayout(hLayout)
        vLayout.addWidget(self.Coor)
#        self.GridLay.addWidget(self.Coor, 1, 1)

        if (self.Obj != "camera" and self.Obj != "light"):
            self.Coor = QGroupBox("Perturbation", self)
            hLayout = QHBoxLayout(self)

            hLayout.addWidget(self.per.Lab_x)
            hLayout.addWidget(self.per.x)
            hLayout.addWidget(self.per.Lab_y)
            hLayout.addWidget(self.per.y)
            hLayout.addWidget(self.per.Lab_z)
            hLayout.addWidget(self.per.z)

            self.Coor.setLayout(hLayout)
            vLayout.addWidget(self.Coor)

            self.Coor = QGroupBox("Effect", self)
            hLayout = QHBoxLayout(self)

            self.effect = effect(self)
            hLayout.addWidget(self.effect.labBrightness)
            hLayout.addWidget(self.effect.Brightness)
            hLayout.addWidget(self.effect.labReflection)
            hLayout.addWidget(self.effect.Reflection)

            self.Coor.setLayout(hLayout)
            self.GridLay.addWidget(self.Coor, 3, 1)

        self.Coor = QGroupBox("Info", self)
        self.Coor.setLayout(vLayout)
        self.GridLay.addWidget(self.Coor, 0, 1)

        if (self.Obj != "camera"):
            self.Coor = QGroupBox("Color / Template", self)
            hLayout = QHBoxLayout(self)

            if (self.Obj != "camera" or self.Obj != "light"):
                button = QPushButton("...", self)
                button.connect(button, SIGNAL("clicked()"), self.setLink)
                hLayout.addWidget(QLabel("Template : "))
                self.labLink = QLabel(self.tem, self)
                hLayout.addWidget(self.labLink)
                hLayout.addWidget(button)
            if (self.Obj != "camera"):
                hLayout.addWidget(QLabel(" Color : "))
                self.labColor = QLabel("000000", self)
                hLayout.addWidget(self.labColor)
                button = QPushButton("...", self)
                button.connect(button, SIGNAL("clicked()"), self.setColor)
                hLayout.addWidget(button)

            self.Coor.setLayout(hLayout)
            self.GridLay.addWidget(self.Coor, 4, 1)

        if (self.Obj != "camera" and self.Obj != "light"):
            self.other = QGroupBox("Other", self)
            self.isNeg = QCheckBox("Negatif", self)
            hLayout = QHBoxLayout(self)

            hLayout.addWidget(self.isNeg)
            if (self.Obj == "sphere"):
                self.rad = QLineEdit("0", self)
                self.rad.connect(self.rad, SIGNAL("editingFinished()"), self.setPrev)
                hLayout.addWidget(QLabel("Radius : "))
                hLayout.addWidget(self.rad)
            if (self.Obj == "cone"):
                self.rad = QLineEdit("0", self)
                self.rad.connect(self.rad, SIGNAL("editingFinished()"), self.setPrev)
                hLayout.addWidget(QLabel("Angle : "))
                hLayout.addWidget(self.rad)
            if (self.Obj == "cylindre"):
                self.rad = QLineEdit("0", self)
                self.rad.connect(self.rad, SIGNAL("editingFinished()"), self.setPrev)
                hLayout.addWidget(QLabel("Randius : "))
                hLayout.addWidget(self.rad)
            if (self.Obj == "tore"):
                self.radLittle = QLineEdit("0", self)
                self.radLittle.connect(self.radLittle, SIGNAL("editingFinished()"), self.setPrev)
                hLayout.addWidget(QLabel("Radius little: "))
                hLayout.addWidget(self.radLittle)
                self.radMax = QLineEdit("0", self)
                self.radMax.connect(self.radMax, SIGNAL("editingFinished()"), self.setPrev)
                hLayout.addWidget(QLabel("Radius Grand: "))
                hLayout.addWidget(self.radMax)

            self.other.setLayout(hLayout)
            self.GridLay.addWidget(self.other, 9, 1)

        hLayout = QHBoxLayout(self)
        act = QPushButton("Ok", self)
        act.connect(act, SIGNAL("clicked()"), self.Parent.getInfo)
        hLayout.addWidget(act)
        act = QPushButton("Quit", self)
        act.connect(act, SIGNAL("clicked()"), self.quit)
        hLayout.addWidget(act)
        self.GridLay.addLayout(hLayout, 10, 1)
        self.show()
        self.setPrev

    def setColor(self):
        c = QColorDialog().getColor()
        self.color = c.name()
        self.labColor.setText(self.color[1:])
        self.setPrev

    def setLink(self):
        self.setEnabled(False)
        fname = QFileDialog.getOpenFileName(self, 'Open file',
                                                  '.')
        link = str(fname)
        if (link):
            self.link = link
            self.labLink.setText(link)
        self.setEnabled(True)
    def ok(self):
        if (self.Parent):
            self.Parent.setEnabled(True)
        self.accept()

    def quit(self):
        if (self.Parent):
            self.Parent.setEnabled(True)
        self.reject()

    def setPrev(self):
        import ui
        self.Run = ui.rayTracer(self)
        prev = "<window y=256 x=256>\n  <scene>\n"
        prev += "    <camera>\n      <location X=-1500 Y=0 Z=0 />\n      <fov>1000</fov>\n    </camera>\n"
        prev += "    <object>" + self.getPrev() + "\n    </object>\n"
        prev += "    <light type=\"diffuse\">\n       <location X=-1000 Y=0 Z=0 />\n      <color>FFFFFF</color>\n      <intensity>0.6</intensity>\n    </light>\n"
        prev += "  </scene>\n</window>"
        y = file("prev.xml", "w")
        y.write(prev)
        y.close()
        self.Run.server = False
        self.Run.m = True
        self.Run.e = True
        self.Run.eLink = "prev.bmp"
        self.Run.run("prev.xml")
        image = ui.uiImage("prev.bmp", self)
        self.GridLay.addWidget(image, 0, 0)
        self.show()

    def getPrev(self):
        s = "\n\t<" + str(self.Obj)
        if (self.isNeg):
            if self.isNeg.isChecked() == False:
                s += " type=\"normal\""
            else:
                s += " type=\"negatif\""
        s += ">\n"
        s += "\t\t" + "<location X=0 Y=0 Z=0 />"
        s += "\n"
        s += "\t\t" + self.rot.getText("rotation")
        s += "\n"
        if (self.Obj != "camera" and self.Obj != "Light" and self.per):
            s += "\t\t" + self.per.getText("perturbation")
            s += "\n"
        if (self.Obj == "sphere"):
            s += "\t\t" + "<radius>" + self.rad.displayText() + "</radius>"
            s += "\n"
        if (self.Obj == "cone"):
            s += "\t\t" + "<radius>" + self.rad.displayText() + "</radius>"
            s += "\n"
        if (self.Obj == "cylindre"):
            s += "\t\t" + "<radius>" + self.rad.displayText() + "</radius>"
            s += "\n"
        if (self.Obj != "camera"):
            s += "\t\t" + "<color>" + str(self.color[1:]).upper() + "</color>"
            s += "\n"
        if (self.link):
            s += "\t\t" + "<template>" + self.link + "</template>"
            s += "\n"
        if (self.effect):
            s += "\t\t" + self.effect.getText()
        s += "\n\t</" + self.Obj + ">"
        return (s)

    def getText(self):
        s = "\n\t<" + self.Obj
        if (self.isNeg):
            if self.isNeg.isChecked() == False:
                s += " type=\"normal\""
            else:
                s += " type=\"negatif\""
        s += ">\n"
        s += "\t\t" + self.pos.getText("location")
        s += "\n"
        s += "\t\t" + self.rot.getText("rotation")
        s += "\n"
        if (self.Obj != "camera" and self.Obj != "Light"):
            s += "\t\t" + self.per.getText("perturbation")
            s += "\n"
        if (self.Obj == "sphere"):
            s += "\t\t" + "<radius>" + self.rad.displayText() + "</radius>"
            s += "\n"
        if (self.Obj == "cone"):
            s += "\t\t" + "<radius>" + self.rad.displayText() + "</radius>"
            s += "\n"
        if (self.Obj == "cylindre"):
            s += "\t\t" + "<radius>" + self.rad.displayText() + "</radius>"
            s += "\n"
        if (self.Obj != "camera"):
            s += "\t\t" + "<color>" + str(self.color[1:]).upper() + "</color>"
            s += "\n"
        if (self.link):
            s += "\t\t" + "<template>" + self.link + "</template>"
            s += "\n"
        if (self.effect):
            s += "\t\t" + self.effect.getText()
        s += "\n\t</" + self.Obj + ">"
        return (s)
