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
import xml.dom.minidom
import ui

class   editUi(uiDialog):
    def __init__(self, Window=None, Text=None, Find=None, t="edit"):
        super(editUi, self).__init__(Window)
        self.Parent = Window
        self.Find = Find
        self.Text = Text
        self.Action = t
        self.init(Window, Text, Find)
        self.setWindowTitle("Edit")

    def init(self, Window, Text, Find):
        self.gridLayout = QGridLayout(self)
        self.createComboBox(self, Find, Text)
        self.gridLayout.addWidget(QLabel("Select : "), 1, 0)
        self.gridLayout.addWidget(self.select, 1, 1)
        hLayout = QHBoxLayout(self)
        act = QPushButton("Ok", self)
        if (self.Action == "edit"):
            act.connect(act, SIGNAL("clicked()"), self.editObject)
        else:
            act.connect(act, SIGNAL("clicked()"), self.removeObject)
        hLayout.addWidget(act)
        act = QPushButton("Quit", self)
        act.connect(act, SIGNAL("clicked()"), self.reject)
        hLayout.addWidget(act)
        self.gridLayout.addLayout(hLayout, 10, 0)
        self.show()

    def createComboBox(self, Window=None, Find=None, Text=None):
        i = Text.count(Find) / 2
        self.select = QComboBox(Window)
        n = 1
        while (i > 0):
            self.select.addItem(Find + str(n))
            n += 1
            i -= 1

    def getObjectText(self):
        s = str(self.select.currentText())
        s = s[(s.find(self.Find) + len(self.Find)):]
        i = int(s) * 2
        n = 0
        while (i > 0):
            n = self.Text.find(self.Find) + len(self.Find)
            i -= 1
        e = ((self.Text[n:]).find(self.Find) + n) + len(self.Find) + 1
        n -= (len(self.Find) + 1)
        r = self.Text[n:e]
        return (r)

    def editObject(self):
        try:
            r = self.getObjectText()
            epx = "0"
            epy = "0"
            epz = "0"
            erx = "0"
            ery = "0"
            erz = "0"
            ecolor = "000000"
            etx = "0"
            ety = "0"
            etz = "0"
            etemplate = None
            doc = xml.dom.minidom.parseString(r)
            for loc in doc.getElementsByTagName("location"):
                if loc.nodeType == loc.ELEMENT_NODE:
                    try:
                        epx = loc.getAttribute("X")
                        epy = loc.getAttribute("Y")
                        epz = loc.getAttribute("Z")
                    except:
                        epx = "0"
                        epy = "0"
                        epz = "0"
            for loc in doc.getElementsByTagName("rotation"):
                if loc.nodeType == loc.ELEMENT_NODE:
                    try:
                        erx = loc.getAttribute("X")
                        ery = loc.getAttribute("Y")
                        erz = loc.getAttribute("Z")
                    except:
                        erx = "0"
                        ery = "0"
                        erz = "0"
            for loc in doc.getElementsByTagName("perturbation"):
                if loc.nodeType == loc.ELEMENT_NODE:
                    try:
                        etx = loc.getAttribute("X")
                        ety = loc.getAttribute("Y")
                        etz = loc.getAttribute("Z")
                    except:
                        etx = "0"
                        ety = "0"
                        etz = "0"
            for loc in doc.getElementsByTagName("color"):
                if loc.nodeType == loc.ELEMENT_NODE:
                    try:
                        ecolor = loc.getText()
                    except:
                        ecolor = "000000"
            for loc in doc.getElementsByTagName("template"):
                if loc.nodeType == loc.ELEMENT_NODE:
                    try:
                        etemplate = loc.getText()
                    except:
                        etemplate = None

        except:
            W = QMessageBox.warning(self, "Warning", "Invalid object", QMessageBox.Ok)
        self.removeObject()
        self.Parent.q = uiAddObject(self.Parent, obj=self.Find, px=epx, py=epy, pz=epz,
                                    rx=erx, ry=ery, rz=erz,
                                    tx=etx, ty=ety, tz=etz,
                                    color=ecolor, template=etemplate)
        self.Parent.q.init(str(self.Find))
        self.reject()

    def removeObject(self):
        r = self.getObjectText()
        xml = str(self.Parent.xml.toPlainText())
        xml = xml[:xml.find(r)] + xml[(xml.find(r) + len(r) + 1):]
        self.Parent.xml.setDocument(QTextDocument(xml))
        self.reject()
