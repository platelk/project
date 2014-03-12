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
                 , x="0", y="0", z="0", Prev=True):
        self.x = None
        self.Lab_x = None

        self.y = None
        self.Lab_y = None

        self.z = None
        self.Lab_z = None

        if (one):
            self.x = QLineEdit(x, Window)
            if (Prev):
                self.x.connect(self.x, SIGNAL("editingFinished()"), Window.setPrev)
            self.Lab_x = QLabel(one, Window)

        if (sec):
            self.y = QLineEdit(y, Window)
            if (Prev):
                self.y.connect(self.y, SIGNAL("editingFinished()"), Window.setPrev)
            self.Lab_y = QLabel(sec, Window)

        if (third):
            self.z = QLineEdit(z, Window)
            if (Prev):
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


class   Perlin:
    def __init__(self, Window=None, color1="0", color2="0"):
        self.Parent = Window
        self.GridLayout = QGridLayout()
        self.GridLayout.addWidget(QLabel("Frequence :"), 0, 0)
        self.Freq = QLineEdit("1", self.Parent)
        self.GridLayout.addWidget(self.Freq, 0, 1)

        self.GridLayout.addWidget(QLabel("Precision : "), 0, 2)
        self.Pres = QLineEdit("1", self.Parent)
        self.GridLayout.addWidget(self.Pres, 0, 3)

        self.GridLayout.addWidget(QLabel("Octave :"), 1, 0)
        self.Oct = QLineEdit("1", self.Parent)
        self.GridLayout.addWidget(self.Oct, 1, 1)

        self.GridLayout.addWidget(QLabel("Relief : "), 1, 2)
        self.Rel = QLineEdit("0 ", self.Parent)
        self.GridLayout.addWidget(self.Rel, 1, 3)

        self.GridLayout.addWidget(QLabel("Color 1 :"), 2, 0)

        self.Col1 = color1
        self.labCol1 = QLabel(self.Col1)
        act = QPushButton("...", self.Parent)
        self.GridLayout.addWidget(self.labCol1, 2, 1)
        self.GridLayout.addWidget(act, 2, 2)
        act.connect(act, SIGNAL("clicked()"), self.setColor1)
        self.GridLayout.addWidget(QLabel("Color 2 :"), 2, 3)

        self.Col2 = color2
        self.labCol2 = QLabel(self.Col2)
        self.GridLayout.addWidget(self.labCol2, 2, 4)
        act = QPushButton("...", self.Parent)
        act.connect(act, SIGNAL("clicked()"), self.setColor2)
        self.GridLayout.addWidget(act, 2, 5)

        self.GridLayout.addWidget(QLabel("Type : "), 3, 0)
        self.Type = QComboBox(self.Parent)
        self.Type.addItem("WOOD")
        self.Type.addItem("MARBEL")
        self.Type.addItem("NONE")
        self.GridLayout.addWidget(self.Type, 3, 1)
        self.GridLayout.addWidget(QLabel("Ceil"), 3, 2)
        self.Ceil = QCheckBox(self.Parent)
        self.GridLayout.addWidget(self.Ceil, 3, 3)

        self.GridLayout.addWidget(QLabel("Perlin :"), 0, 4)
        self.On = QCheckBox(self.Parent)
        self.GridLayout.addWidget(self.On, 0, 5)

        self.GridLayout.addWidget(QLabel("Apply"), 3, 4)
        self.Apply = QComboBox(self.Parent)
        self.Apply.addItem("BUMP")
        self.Apply.addItem("TEXTURE")
        self.Apply.addItem("BUMP_TEXTURE")
        self.GridLayout.addWidget(self.Apply, 3, 5)

    def getText(self):
        if (self.On.isChecked() == True):
            s = "<perlin "
            s += "FREQUENCE=\"" + self.Freq.displayText() + "\" "
            s += "PERSISTANCE=\"" + self.Pres.displayText() + "\" "
            s += "OCTAVE=\"" + self.Oct.displayText() + "\" "
            s += "RELIEF=\"" + self.Rel.displayText() + "\" "
            s += "CEIL=\""
            if (self.Ceil.isChecked() == False):
                s += "OFF"
            else:
                s += "ON"
            s += "\" "
            s += "COLOR1=\"" + str(self.Col1)[1:].upper() + "\" "
            s += "COLOR2=\"" + str(self.Col2)[1:].upper() + "\" "
            s += "APPLY=\"" + self.Apply.currentText() + "\" "
            s += "TYPE=\"" + self.Type.currentText() + "\""
            s += "/>"
        else:
            s = ""
        return (s)

    def setColor1(self):
        c = QColorDialog().getColor()
        self.Col1 = c.name()
        self.labCol1.setText(self.Col1[1:])

    def setColor2(self):
        c = QColorDialog().getColor()
        self.Col2 = c.name()
        self.labCol2.setText(self.Col2[1:])

class   Bump:
    def __init__(self, Window=None):
        self.Parent = Window

        self.isBump = QCheckBox(self.Parent)

        self.GridLayout = QGridLayout(self.Parent)
        self.GridLayout.addWidget(QLabel("Bump"), 0, 0)
        self.Path = ""
        self.labPath = QLabel(self.Path)
        self.GridLayout.addWidget(self.labPath, 0, 1)
        act = QPushButton("...", self.Parent)
        act.connect(act, SIGNAL("clicked()"), self.setLink)
        self.GridLayout.addWidget(act, 0, 2)
        self.GridLayout.addWidget(QLabel("Frequence : "), 0, 3)
        self.Freq = QLineEdit("1.0")
        self.GridLayout.addWidget(self.Freq, 0, 4)

        self.GridLayout.addWidget(QLabel("Relief : "), 0, 5)
        self.Rel = QLineEdit("1.0")
        self.GridLayout.addWidget(self.Rel, 0, 6)
        self.GridLayout.addWidget(self.isBump)

        self.Type = QComboBox(self.Parent)
        self.Type.addItem("NORMAL")
        self.Type.addItem("BUMP")

        self.GridLayout.addWidget(QLabel("Type"), 0, 7)

        self.GridLayout.addWidget(self.Type, 0, 8)

    def setLink(self):
        self.Parent.setEnabled(False)
        fname = QFileDialog.getOpenFileName(self.Parent, 'Open file',
                                                  '.')
        link = str(fname)
        if (link):
            self.Path = link
            self.labPath.setText(link)
        self.Parent.setEnabled(True)
    def getText(self):
        if (self.isBump.isChecked() == True):
            s = "<bump_mapping "
            s += " FREQUENCE=\"" + self.Freq.displayText() + "\""
            s += " RELIEF=\"" + self.Rel.displayText() + "\""
            s += " TYPE=\"" + self.Type.currentText() + "\""
            s += " >"
            s += str(self.Path)
            s += "</bump_mapping>"
        else:
            s = ""
        return (s)

class   Texture:
    def __init__(self, Window=None):
        self.Parent = Window
        self.GridLayout = QGridLayout(self.Parent)
        self.Color = None
        self.link = None

        button = QPushButton("...", self.Parent)
        button.connect(button, SIGNAL("clicked()"), self.setLink)
        self.GridLayout.addWidget(QLabel("Template : "), 0, 0)
        self.labLink = QLabel(self.Parent.tem, self.Parent)
        self.GridLayout.addWidget(self.labLink, 0, 1)
        self.GridLayout.addWidget(button, 0, 2)
        self.Type = QComboBox(self.Parent)
        self.Type.addItem("cut")
        self.Type.addItem("None")
        self.labColor = QLabel("000000")
        self.GridLayout.addWidget(QLabel("Color : "), 0, 3)
        self.GridLayout.addWidget(self.labColor, 0, 4)
        button = QPushButton("...", self.Parent)
        button.connect(button, SIGNAL("clicked()"), self.setColor)
        self.GridLayout.addWidget(button, 0, 5)
        self.GridLayout.addWidget(QLabel("Type :"), 0, 6)
        self.GridLayout.addWidget(self.Type, 0, 7)
        self.Keep = QCheckBox()
        self.GridLayout.addWidget(QLabel("Keep :"), 1, 0)
        self.GridLayout.addWidget(self.Keep, 1, 1)
        self.GridLayout.addWidget(QLabel("Frequence : "), 1, 2)
        self.Freq = QLineEdit("0.0", self.Parent)
        self.GridLayout.addWidget(self.Freq, 1, 3)
        self.GridLayout.addWidget(QLabel("Interval : "), 1, 4)
        self.Inter = QLineEdit("0.0", self.Parent)
        self.GridLayout.addWidget(self.Inter, 1, 5)

    def setColor(self):
        c = QColorDialog().getColor()
        self.Color = c.name()
        self.labColor.setText(self.Color[1:])

    def setLink(self):
        self.Parent.setEnabled(False)
        fname = QFileDialog.getOpenFileName(self.Parent, 'Open file',
                                            '.')
        link = str(fname)
        if (link):
            self.link = link
            self.labLink.setText(link)
        self.Parent.setEnabled(True)

    def getText(self):
        if (self.link):
            r = "<texture TYPE=\"" + self.Type.currentText() + "\" "
            r += "COLOR=\"" + str(self.Color) + "\" "
            r += "KEEP=\""
            if (self.Keep.isChecked() == True):
                r += "yes" + "\" "
            else:
                r += "no" + "\" "
            r += "FREQUENCE=\"" + str(self.Freq.displayText()) + "\" "
            r += "INTERVAL=\"" + str(self.Inter.displayText()) + "\" "
            r += " >"
            r += str(self.link)
            r += "</texure>"
        else:
            r = ""
        return (r)

class effect:
    def __init__(self, Window):
        self.Brightness = QSlider(0x1, Window)
        self.labBrightness = QLabel("Brightness", Window)
        self.Brightness.setMaximum(100)
        self.Brightness.setMinimum(0)
        self.Brightness.connect(self.Brightness, SIGNAL("sliderReleased()"), Window.setPrev)

        self.Phong = QSlider(0x1, Window)
        self.labPhong = QLabel("Phong", Window)
        self.Phong.setMaximum(1000)
        self.Phong.setMinimum(1)
        self.Phong.connect(self.Phong, SIGNAL("sliderReleased()"), Window.setPrev)

        self.Transparency = QSlider(0x1, Window)
        self.labTransparency = QLabel("Transparency", Window)
        self.Transparency.setMaximum(100)
        self.Transparency.setMinimum(0)
        self.Transparency.connect(self.Transparency, SIGNAL("sliderReleased()"), Window.setPrev)

        self.Reflection = QSlider(0x1, Window)
        self.labReflection = QLabel("Reflection", Window)
        self.Reflection.setMaximum(100)
        self.Reflection.setMinimum(0)
        self.Reflection.connect(self.Reflection, SIGNAL("sliderReleased()"), Window.setPrev)

    def getText(self):
        r = "<effect BRIGHTNESS=\""
        r +=  str(float(self.Brightness.sliderPosition()) / 100.0)
        r +=  "\" REFLECTION=\"" + str(float(self.Reflection.sliderPosition()) / 100.0)
        r += "\" " + "PHONG=\"" + str(float(self.Phong.sliderPosition()))
        r += "\" TRANSPARENCY=\""+ str(float(self.Transparency.sliderPosition()) / 100.0) + "\" />"
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
        self.Template = None
        self.Perl = None
        self.Bump = None
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

            self.Coor = QGroupBox("Perlin", self)
            self.Perl = Perlin(self)
            self.Coor.setLayout(self.Perl.GridLayout)
            vLayout.addWidget(self.Coor)
            self.Coor = QGroupBox("Bump", self)

            self.Bump = Bump(self)
            self.Coor.setLayout(self.Bump.GridLayout)
            vLayout.addWidget(self.Coor)


            self.Coor.setLayout(hLayout)
            vLayout.addWidget(self.Coor)

            self.Coor = QGroupBox("Effect", self)
            hLayout = QHBoxLayout(self)

            self.effect = effect(self)
            hLayout.addWidget(self.effect.labBrightness)
            hLayout.addWidget(self.effect.Brightness)
            hLayout.addWidget(self.effect.labPhong)
            hLayout.addWidget(self.effect.Phong)
            hLayout.addWidget(self.effect.labTransparency)
            hLayout.addWidget(self.effect.Transparency)
            hLayout.addWidget(self.effect.labReflection)
            hLayout.addWidget(self.effect.Reflection)

            self.Coor.setLayout(hLayout)
            self.GridLay.addWidget(self.Coor, 1, 1)

        self.Coor = QGroupBox("Info", self)
        self.Coor.setLayout(vLayout)
        self.GridLay.addWidget(self.Coor, 0, 1)

        if (self.Obj != "camera"):
            hLayout = QHBoxLayout(self)

            if (self.Obj != "camera" or self.Obj != "light"):
                self.Coor = QGroupBox("Template", self)
                self.Template = Texture(self)
                self.Coor.setLayout(self.Template.GridLayout)
                self.GridLay.addWidget(self.Coor, 6, 1)
            if (self.Obj != "camera"):
                self.Coor = QGroupBox("Color", self)
                hLayout.addWidget(QLabel(" Color : "))
                self.labColor = QLabel("000000", self)
                hLayout.addWidget(self.labColor)
                button = QPushButton("...", self)
                button.connect(button, SIGNAL("clicked()"), self.setColor)
                hLayout.addWidget(button)

            self.Coor.setLayout(hLayout)
            self.GridLay.addWidget(self.Coor, 7, 1)

        if (self.Obj != "camera" and self.Obj != "light"):
            self.other = QGroupBox("Other", self)
            self.isNeg = QCheckBox("Negatif", self)

            hLayout.addWidget(QLabel("Antialiasing : "))
            self.Anti = QLineEdit("1")
            hLayout.addWidget(self.Anti)
            hLayout.addWidget(self.isNeg)
            if (self.Obj == "sphere"):
                self.rad = QLineEdit("0", self)
                self.rad.connect(self.rad, SIGNAL("editingFinished()"), self.setPrev)
                hLayout.addWidget(QLabel("Radius : "))
                hLayout.addWidget(self.rad)
            if (self.Obj == "paraboloide"):
                self.rad = QLineEdit("0", self)
                self.rad.connect(self.rad, SIGNAL("editingFinished()"), self.setPrev)
                hLayout.addWidget(QLabel("Radius : "))
                hLayout.addWidget(self.rad)
            if (self.Obj == "cubetroue"):
                self.rad1 = QLineEdit("0", self)
                self.rad1.connect(self.rad1, SIGNAL("editingFinished()"), self.setPrev)
                hLayout.addWidget(QLabel("Radius : "))
                hLayout.addWidget(self.rad1)
                self.rad2 = QLineEdit("0", self)
                self.rad2.connect(self.rad2, SIGNAL("editingFinished()"), self.setPrev)
                hLayout.addWidget(QLabel("Size : "))
                hLayout.addWidget(self.rad2)
            if (self.Obj == "hyper"):
                self.rad1 = QLineEdit("0", self)
                self.rad1.connect(self.rad1, SIGNAL("editingFinished()"), self.setPrev)
                hLayout.addWidget(QLabel("Radius : "))
                hLayout.addWidget(self.rad1)
                self.rad2 = QLineEdit("0", self)
                self.rad2.connect(self.rad2, SIGNAL("editingFinished()"), self.setPrev)
                hLayout.addWidget(QLabel("Size : "))
                hLayout.addWidget(self.rad2)
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
                self.rad1 = QLineEdit("0", self)
                self.rad1.connect(self.rad1, SIGNAL("editingFinished()"), self.setPrev)
                hLayout.addWidget(QLabel("Toll radius : "))
                hLayout.addWidget(self.rad1)
                self.rad2 = QLineEdit("0", self)
                self.rad2.connect(self.rad2, SIGNAL("editingFinished()"), self.setPrev)
                hLayout.addWidget(QLabel("Small radius : "))
                hLayout.addWidget(self.rad2)

            self.other.setLayout(hLayout)
            self.GridLay.addWidget(self.other, 8, 1)

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

    def ok(self):
        if (self.Parent):
            self.Parent.setEnabled(True)
        self.accept()

    def quit(self):
        if (self.Parent):
            self.Parent.setEnabled(True)
        self.reject()

    def setPrev(self):
        if (self.Obj != "camera" and self.Obj != "light"):
            import ui
            self.Run = ui.rayTracer(self)
            prev = "<window Y=256 X=256>\n  <scene ANTIALIASING=" + str(self.Anti.displayText()) + " >\n"
            prev += "    <camera>\n      <location X=-1500 Y=0 Z=0 />\n      <fov>1000</fov>\n    </camera>\n"
            prev += "    <object>" + self.getPrev() + "\n    </object>\n"
            prev += "    <light TYPE=\"diffuse\">\n       <location X=-1000 Y=0 Z=0 />\n      <color>FFFFFF</color>\n      <intensity>0.6</intensity>\n    </light>\n"
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
                s += " TYPE=\"normal\""
            else:
                s += " TYPE=\"negatif\""
        s += ">\n"
        s += "\t\t" + "<location X=0 Y=0 Z=0 />"
        s += "\n"
        if (self.Perl.On.isChecked() == True):
            s += "\t\t" + self.Perl.getText()
            s += "\n"
        if (self.Bump.isBump.isChecked() == True):
            s += "\t\t" + self.Bump.getText()
            s += "\n"
        s += "\t\t" + self.Template.getText()
        s += "\n"
        s += "\t\t" + self.rot.getText("rotation")
        s += "\n"
        if (self.Obj != "camera" and self.Obj != "Light" and self.per):
            s += "\t\t" + self.per.getText("perturbation")
            s += "\n"
        if (self.Obj == "sphere"):
            s += "\t\t" + "<radius>" + str(self.rad.displayText()) + "</radius>"
            s += "\n"
        if (self.Obj == "paraboloide"):
            s += "\t\t" + "<radius>" + str(self.rad.displayText()) + "</radius>"
            s += "\n"
        if (self.Obj == "tore"):
            s += "\t\t" + "<radius MAX=\"" + str(self.rad1.displayText()) + "\" "
            s += "MIN=\"" + str(self.rad2.displayText()) + "\" />"
            s += "\n"
        if (self.Obj == "cone"):
            s += "\t\t" + "<radius>" + str(self.rad.displayText()) + "</radius>"
            s += "\n"
        if (self.Obj == "cylindre"):
            s += "\t\t" + "<radius>" + str(self.rad.displayText()) + "</radius>"
            s += "\n"
        if (self.Obj == "cubetroue"):
            s += "\t\t" + "<radius>" + str(self.rad1.displayText()) + "</radius>"
            s += "\n"
            s += "\t\t" + "<size>" + self.rad2.displayText() + "</size>"
        if (self.Obj != "camera"):
            s += "\t\t" + "<color>" + str(self.color[1:]).upper() + "</color>"
            s += "\n"
        if (self.effect):
            s += "\t\t" + self.effect.getText()
        s += "\n\t</" + self.Obj + ">"
        return (s)

    def getText(self):
        s = "\n\t<" + self.Obj
        if (self.isNeg):
            if self.isNeg.isChecked() == False:
                s += " TYPE=\"normal\""
            else:
                s += " TYPE=\"negatif\""
        s += ">\n"
        s += "\t\t" + self.pos.getText("location")
        s += "\n"
        s += "\t\t" + self.rot.getText("rotation")
        s += "\n"
        if (self.Perl):
            s += "\t\t" + self.Perl.getText()
            s += "\n"
        if (self.Bump):
            s += "\t\t" + self.Bump.getText()
            s += "\n"
        if (self.Template):
            s += "\t\t" + self.Template.getText()
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
        if (self.Obj == "tore"):
            s += "\t\t" + "<radius MAX=\"" + self.rad1.displayText() + "\" "
            s += "MIN=\"" + self.rad2.displayText() + "\" />"
            s += "\n"
        if (self.Obj == "cubetroue"):
            s += "\t\t" + "<radius>" + self.rad1.displayText() + "</radius>"
            s += "\n"
            s += "\t\t" + "<size>" + self.rad2.displayText() + "</size>"
            s += "\n"
        if (self.Obj == "paraboloide"):
            s += "\t\t" + "<radius>" + self.rad.displayText() + "</radius>"
            s += "\n"
        if (self.Obj == "cylindre"):
            s += "\t\t" + "<radius>" + self.rad.displayText() + "</radius>"
            s += "\n"
        if (self.Obj != "camera"):
            s += "\t\t" + "<color>" + str(self.color[1:]).upper() + "</color>"
            s += "\n"
        if (self.effect):
            s += "\t\t" + self.effect.getText()
        s += "\n\t</" + self.Obj + ">"
        return (s)
