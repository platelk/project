#!/usr/bin/python2.7

#Made by Vink

import sys
import os

from xml.dom import minidom
from obj import *
from sub_ui import *
from edit_ui import *
from new_ui import *
from ui_movie import *

import commands
import time
try:
    from PyQt4.QtCore import *  # Moteur controle Qt
    from PyQt4.QtGui import *   # IHM Qt
except:
    import time                 # Gestion heures systeme
    for i in range(1, 11):
        print ("PyQt is not install - check in (%d/10)", i)
        time.sleep(5)
        sys.exit(1)

#############################
###### UiButton #############
#############################

class   uiButton(QPushButton):
    def __init__(self, Window, title='button', height=50, width=50,
                 setToolTip='This is a <b>QPushButton</b> widget'):
        super(uiButton, self).__init__(title, Window)
        self.init(Window, title, height, width, setToolTip)
    def init(self, Window, title='button', height=50, width=50,
                 setToolTip='This is a <b>QPushButton</b> widget'):
        self.setToolTip('This is a <b>QPushButton</b> widget')
        self.resize(self.sizeHint())
        self.move(height, width)

#############################

#############################
###### UiImage  #############
#############################

class   uiAllImage:
    def __init__(self):
        self.Image = list()

    def addImage(self, img):
        self.Image.append(img)
        return (len(self.Image))

class   uiImage(QLabel):
    def __init__(self, path=None, Window=None):
        super(uiImage, self).__init__("Image", Window)
        self.Parent = Window
        if (path):
            img = QPixmap(path)
            self.setPixmap(img)
            self.Name = (path)

    def setImage(self, i=0, path=None):
        if (path):
            img = QPixmap(path)
            self.setPixmap(img)
        else:
            img = QPixmap(self.Parent.allImg.Image[i])
            self.setPixmap(img)

#############################

#############################
###### UiAction #############
#############################

class   uiAction(QAction):
    def __init__(self, Window, act, path=None, Shortcut=None, status=None, connect=None, icon=None):
        if (icon == None):
            super(uiAction, self).__init__(act, Window)
        else:
            super(uiAction, self).__init__(icon, act, Window)
        if (Shortcut):
            self.setShortcut(Shortcut)
        if (status):
            self.setStatusTip(status)
        if (connect):
            self.connect(connect)
    def connect(self, connect):
        self.triggered.connect(connect)

#############################

#############################
###### UiMenu   #############
#############################

class   uiMenu(QMenu):
    def __init__(self, title, Window):
        super(uiMenu, self).__init__(title, Window)
        self.Action = dict()
    def addEvent(self, act, Name):
        self.Action[Name] = act
        self.addAction(self.Action[Name])

#############################

#############################
###### UiMenuBar ############
#############################

class   uiMenuBar(QMenuBar):
    def __init__(self, Window):
        super(uiMenuBar, self).__init__(Window)
        self.Menu = dict()

    def addAction(self, action, name, menu='&File'):
        self.Menu[name] = self.addMenu(menu)
        self.Menu[name].addAction(action)

#############################

#############################
###### UiMainWindow #########
#############################

class   rayTracer:
    def __init__(self, Window, client=None, c_ip=None, c_port=None, c_thread="1", server=False, s_port=None,
                 m=True, e=False, eLink=""):
        self.Parent       = Window
        self.client       = None
        self.c_ip         = None
        self.c_port       = None
        self.c_thread     = 1
        self.server       = False
        self.s_port       = None
        self.m            = True
        self.e            = False
        self.eLink        = ""
        self.v            = False
        self.t            = "1"

        self.gridLayout = None

    def run(self, link):
        s = "./raytracer " + link
        if (self.server):
            s += " --server"
            if (self.s_port):
                s += " -p " + self.s_port
        if (self.e):
            s += " -e " + self.eLink
        if (self.v):
            s += " -v"
        if (not self.server and self.t):
            s += " -t " + self.t
        if (self.m):
            s += " -m"
        if (self.client):
            s += " --client"
            if (self.c_ip):
                s += " -i " + self.c_ip
            if (self.c_port):
                s += "-p " + self.c_port
            if (self.c_thread):
                s += "-t " + self.c_thread
        os.system(str(s))

    def getInfo(self):
        if (self.e):
            self.eLink = self.exportLink.displayText()
        self.t = self.nbThread.displayText()
        self.s_port = self.portServer.displayText()

    def setInfo(self, Window):
        self.gridLayout = QGridLayout(Window)
        r = QGroupBox("Raytracer", Window)
        t = QGridLayout(Window)

        self.mStatus = QCheckBox("Rt Display", Window)
        t.addWidget(self.mStatus, 0, 0)
        self.mStatus.connect(self.mStatus, SIGNAL("stateChanged()"), self.changeMStatus)
        self.vStatus = QCheckBox("Scene describe", Window)
        t.addWidget(self.vStatus, 1, 0)
        self.vStatus.connect(self.vStatus, SIGNAL("stateChanged()"), self.changeVStatus)
        t.addWidget(QLabel("Thread :"), 2, 0)
        self.nbThread = QLineEdit("1", Window)
        t.addWidget(self.nbThread, 2, 1)

        r.setLayout(t)
        self.gridLayout.addWidget(r, 0, 0)

        r = QGroupBox("Exportation")
        t = QGridLayout(Window)
        self.checkExport = QCheckBox("Export", Window)
        self.checkExport.connect(self.checkExport, SIGNAL("clicked()"), self.changeExportStatus)
        t.addWidget(self.checkExport, 0, 0)
        t.addWidget(QLabel("Name :"), 1, 0)
        self.exportLink = QLineEdit("Test", Window)
        self.exportLink.setEnabled(False)
        t.addWidget(self.exportLink, 1, 1)
        r.setLayout(t)
        self.gridLayout.addWidget(r, 1, 0)

        r = QGroupBox("Serveur")
        t = QGridLayout(Window)
        self.checkServer = QCheckBox("Server", Window)
        self.checkServer.connect(self.checkServer, SIGNAL("clicked()"), self.changeServerStatus)
        self.portServer = QLineEdit("0", Window)
        t.addWidget(self.checkServer, 0, 0)
        t.addWidget(QLabel("Port : "))
        t.addWidget(self.portServer, 1, 1)
        r.setLayout(t)
        self.portServer.setEnabled(self.server)
        self.gridLayout.addWidget(r, 20, 0)

    def changeServerStatus(self):
        self.server = not self.server
        self.portServer.setEnabled(self.server)

    def changeMStatus(self):
        self.m = not self.m

    def changeVStatus(self):
        self.v = not self.v

    def changeExportStatus(self):
        self.e = not self.e
        self.exportLink.setEnabled(self.e)

class   uiMainWindow(QMainWindow):

    def __init__(self, height=400, width=400):
        super(uiMainWindow, self).__init__()

        self.Run = rayTracer(self)
        self.Menu = dict()
        self.Action = dict()
        self.Name = None
        self.toolBar = None
        self.Image = uiImage(Window=self)
        self.ImagePath = None
        self.button = dict()
        self.head = None
        self.foot = None
        self.allImg = None
        self.scene = None
        self.win_x = None
        self.win_y = None

        self.initUI(height, width)

    def initUI(self, height, width):

        QToolTip.setFont(QFont('SansSerif', 10))

        self.setToolTip('This is a <b>QWidget</b> widget')
        #bottomBar = QTabWidget(self)

######### Creation of Menu
        self.createAction()
        self.createMenu()
        self.createToolBar()
        self.createCentralMenu()
        self.createLeftMenu()

        self.setGeometry(0, 0, height, width)
#       self.resize.connect(self.MainResize)
        self.MainResize()

        self.setWindowTitle('Interface')
        self.show()

###########
    def MainResize(self):
        self.menu_width = self.width() / 7
        self.menu_height = self.width() / 7
        self.menu_start = self.height() / 12
        size_menubar = 30

        self.toolBar.setGeometry(0, size_menubar, 550, self.menu_start - size_menubar)
        self.central.setGeometry(self.menu_width, self.menu_start,
                                 self.width() - (self.menu_width),
                                 self.height() - ((self.menu_start - size_menubar)) - size_menubar)
        self.leftBar.setGeometry(0, self.menu_start, self.menu_width, self.height() - self.menu_start)
        self.menubar.setGeometry(0,0, 250, size_menubar)

    def createAction(self):

        self.Action["New"] = uiAction(self,
                                      '&New',
                                      connect=self.newFile,
                                      icon=QIcon("./icone/new.jpg"))
        self.Action["Open"] = uiAction(self,
                                       '&Open',
                                       connect=self.openFile,
                                       icon=QIcon("./icone/open.jpg"),
                                       Shortcut="Ctrl+o")
        self.Action["Save"] = uiAction(self,
                                       '&Save',
                                       connect=self.saveFile,
                                       icon=QIcon("./icone/save.jpg"),
                                       Shortcut="Ctrl+s")
        self.Action["Save"].setEnabled(False)
        self.Action["SaveAs"] = uiAction(self,
                                         '&SaveAs',
                                         connect=self.saveToFile,
                                         icon=QIcon("./icone/save.png"),
                                         Shortcut="Ctrl+Shift+s")
        self.Action["SaveAs"].setEnabled(False)
        self.Action["Run"] = uiAction(self,
                                       '&Run',
                                       connect=self.runRayTracer,
                                       icon=QIcon("./icone/run.jpg"),
                                       Shortcut="Ctrl+r")
        self.Action["Movie"] = uiAction(self,
                                        '&Movie',
                                        connect=self.creationMovie,
                                        icon=QIcon("./icone/movie.jpg")
                                        )
        self.Action["Camera"] = uiAction(self,
                                         '&Camera',
                                         connect=self.addCamera,
                                         icon=QIcon("./icone/camera.jpg"),
                                         Shortcut="Ctrl+Alt+c")
        self.Action["Camera"].setEnabled(False)
        self.Action["Light"] = uiAction(self,
                                         '&Light',
                                         connect=self.addLight,
                                         icon=QIcon("./icone/lumiere.jpg"),
                                         Shortcut="Ctrl+Alt+l")
        self.Action["Light"].setEnabled(False)
        self.Action["Plan"] = uiAction(self,
                                         '&Plan',
                                         connect=self.addPlan,
                                         icon=QIcon("./icone/sphere.png"),
                                         Shortcut="Ctrl+Alt+s")
        self.Action["Plan"].setEnabled(False)
        self.Action["Sphere"] = uiAction(self,
                                         '&Sphere',
                                         connect=self.addSphere,
                                         icon=QIcon("./icone/sphere.jpg"),
                                         Shortcut="Ctrl+Alt+s")
        self.Action["Sphere"].setEnabled(False)
        self.Action["Cylindre"] = uiAction(self,
                                         '&Cylindre',
                                         connect=self.addCylindre,
                                         icon=QIcon("./icone/sphere.png"),
                                         Shortcut="Ctrl+Alt+y")
        self.Action["Cylindre"].setEnabled(False)
        self.Action["Cone"] = uiAction(self,
                                         '&Cone',
                                         connect=self.addCylindre,
                                         icon=QIcon("./icone/cone.jpg"),
                                         Shortcut="Ctrl+Alt+o")
        self.Action["Cone"].setEnabled(False)
        self.Action["Tore"] = uiAction(self,
                                         '&Tore',
                                         connect=self.addTore,
                                         icon=QIcon("./icone/cone.jpg"),
                                         Shortcut="Ctrl+Alt+o")
        self.Action["Tore"].setEnabled(False)
        self.Action["Cubetroue"] = uiAction(self,
                                         '&Cubetroue',
                                         connect=self.addCubetroue,
                                         icon=QIcon("./icone/cone.jpg"),
                                         Shortcut="Ctrl+Alt+o")
        self.Action["Cubetroue"].setEnabled(False)
        self.Action["Paraboloide"] = uiAction(self,
                                         '&Paraboloide',
                                         connect=self.addPara,
                                         icon=QIcon("./icone/cone.jpg"),
                                         Shortcut="Ctrl+Alt+o")
        self.Action["Paraboloide"].setEnabled(False)
        self.Action["Image"] = uiAction(self,
                                        '&Image',
                                        connect=self.getImage,
                                        icon=QIcon("./icone/image.png"))
        self.Action["editCamera"] = uiAction(self,
                                         '&Camera',
                                         connect=self.addCamera,
                                         icon=QIcon("./icone/sphere.png"),
                                         Shortcut="Ctrl+Alt+c")
        self.Action["editCamera"].setEnabled(False)
        self.Action["editLight"] = uiAction(self,
                                         '&Light',
                                         connect=self.editLight,
                                         icon=QIcon("./icone/sphere.png"),
                                         Shortcut="Ctrl+Alt+l")
        self.Action["editLight"].setEnabled(False)
        self.Action["editPlan"] = uiAction(self,
                                         '&Plan',
                                         connect=self.editPlan,
                                         icon=QIcon("./icone/sphere.png"),
                                         Shortcut="Ctrl+Alt+s")
        self.Action["editPlan"].setEnabled(False)
        self.Action["editSphere"] = uiAction(self,
                                         '&Sphere',
                                         connect=self.editSphere,
                                         icon=QIcon("./icone/sphere.png"),
                                         Shortcut="Ctrl+Alt+s")
        self.Action["editSphere"].setEnabled(False)
        self.Action["editCylindre"] = uiAction(self,
                                         '&Cylindre',
                                         connect=self.editCylindre,
                                         icon=QIcon("./icone/sphere.png"),
                                         Shortcut="Ctrl+Alt+y")
        self.Action["editCylindre"].setEnabled(False)
        self.Action["editCone"] = uiAction(self,
                                         '&Cone',
                                         connect=self.editCone,
                                         icon=QIcon("./icone/sphere.png"),
                                         Shortcut="Ctrl+Alt+o")
        self.Action["editCone"].setEnabled(False)
        self.Action["remCamera"] = uiAction(self,
                                         '&Camera',
                                         connect=self.remCamera,
                                         icon=QIcon("./icone/sphere.png"),
                                         Shortcut="Ctrl+Alt+c")
        self.Action["remCamera"].setEnabled(False)
        self.Action["remLight"] = uiAction(self,
                                         '&Light',
                                         connect=self.remLight,
                                         icon=QIcon("./icone/sphere.png"),
                                         Shortcut="Ctrl+Alt+l")
        self.Action["remLight"].setEnabled(False)
        self.Action["remPlan"] = uiAction(self,
                                         '&Plan',
                                         connect=self.remPlan,
                                         icon=QIcon("./icone/sphere.png"),
                                         Shortcut="Ctrl+Alt+s")
        self.Action["remPlan"].setEnabled(False)
        self.Action["remSphere"] = uiAction(self,
                                         '&Sphere',
                                         connect=self.remSphere,
                                         icon=QIcon("./icone/sphere.png"),
                                         Shortcut="Ctrl+Alt+s")
        self.Action["remSphere"].setEnabled(False)
        self.Action["remCylindre"] = uiAction(self,
                                         '&Cylindre',
                                         connect=self.remCylindre,
                                         icon=QIcon("./icone/sphere.png"),
                                         Shortcut="Ctrl+Alt+y")
        self.Action["remCylindre"].setEnabled(False)
        self.Action["remCone"] = uiAction(self,
                                         '&Cone',
                                         connect=self.remCone,
                                         icon=QIcon("./icone/sphere.png"),
                                         Shortcut="Ctrl+Alt+o")
        self.Action["remCone"].setEnabled(False)
        self.Action["Exit"] = uiAction(self,
                                       '&Exit',
                                       connect=qApp.quit,
                                       icon=QIcon("./icone/exit.png"),
                                       Shortcut="Ctrl+q")

    def createToolBar(self):
        self.toolBar = QToolBar("Tools", self)

        self.toolBar.addAction(self.Action["New"])
        self.toolBar.addAction(self.Action["Open"])
        self.toolBar.addAction(self.Action["Save"])
        self.toolBar.addAction(self.Action["SaveAs"])
        self.toolBar.addAction(self.Action["Exit"])
        self.toolBar.addSeparator()
        self.toolBar.addAction(self.Action["Run"])
        self.toolBar.addAction(self.Action["Movie"])
        self.toolBar.addSeparator()
        self.toolBar.addAction(self.Action["Sphere"])
        self.toolBar.addAction(self.Action["Plan"])
        self.toolBar.addAction(self.Action["Cone"])
        self.toolBar.addAction(self.Action["Cylindre"])
        self.toolBar.addAction(self.Action["Tore"])
        self.toolBar.addAction(self.Action["Cubetroue"])
        self.toolBar.addAction(self.Action["Paraboloide"])
        self.toolBar.addSeparator()
        self.toolBar.addAction(self.Action["Camera"])
        self.toolBar.addAction(self.Action["Light"])


    def createMenu(self):
        self.menubar = uiMenuBar(self)

        self.Menu["File"] = uiMenu("File", self)

        self.Menu["File"].addAction(self.Action["New"])
        self.Menu["File"].addAction(self.Action["Save"])
        self.Menu["File"].addAction(self.Action["SaveAs"])
        self.Menu["File"].addAction(self.Action["Open"])
        self.Menu["File"].addAction(self.Action["Exit"])

        self.Menu["Tools"] = uiMenu("Tools", self)
        self.Menu["Tools"].addEvent(self.Action["Image"], "Image")

        self.Menu["Edit"] = uiMenu("Edit", self)
        ##
        self.Menu["Object"] = uiMenu("Object", self)
        ####
        self.Menu["AddObj"] = uiMenu("Add", self)
        ######
        self.Menu["AddObj"].addAction(self.Action["Plan"])
        self.Menu["AddObj"].addAction(self.Action["Sphere"])
        self.Menu["AddObj"].addAction(self.Action["Cylindre"])
        self.Menu["AddObj"].addAction(self.Action["Cone"])
        self.Menu["AddObj"].addAction(self.Action["Tore"])
        self.Menu["AddObj"].addAction(self.Action["Cubetroue"])
        self.Menu["AddObj"].addAction(self.Action["Paraboloide"])
        ######
        self.Menu["editObj"] = uiMenu("edit", self)
        ######
        self.Menu["editObj"].addAction(self.Action["editPlan"])
        self.Menu["editObj"].addAction(self.Action["editSphere"])
        self.Menu["editObj"].addAction(self.Action["editCylindre"])
        self.Menu["editObj"].addAction(self.Action["editCone"])
        ######
        self.Menu["remObj"] = uiMenu("remove", self)
        ######
        self.Menu["remObj"].addAction(self.Action["remPlan"])
        self.Menu["remObj"].addAction(self.Action["remSphere"])
        self.Menu["remObj"].addAction(self.Action["remCylindre"])
        self.Menu["remObj"].addAction(self.Action["remCone"])
        ######
        self.Menu["Object"].addMenu(self.Menu["AddObj"])
        self.Menu["Object"].addMenu(self.Menu["editObj"])
        self.Menu["Object"].addMenu(self.Menu["remObj"])
        ####
        self.Menu["Camera"] = uiMenu("Camera", self)
        self.Menu["AddCam"] = uiMenu("Add", self)
        self.Menu["AddCam"].addAction(self.Action["Camera"])
        self.Menu["editCam"] = uiMenu("edit", self)
        self.Menu["editCam"].addAction(self.Action["editCamera"])
        self.Menu["remCam"] = uiMenu("remove", self)
        self.Menu["remCam"].addAction(self.Action["remCamera"])
        self.Menu["Camera"].addMenu(self.Menu["AddCam"])
        self.Menu["Camera"].addMenu(self.Menu["editCam"])
        self.Menu["Camera"].addMenu(self.Menu["remCam"])

        self.Menu["Light"] = uiMenu("Light", self)
        self.Menu["AddLight"] = uiMenu("Add", self)
        self.Menu["AddLight"].addAction(self.Action["Light"])
        self.Menu["editLight"] = uiMenu("edit", self)
        self.Menu["editLight"].addAction(self.Action["editLight"])
        self.Menu["remLight"] = uiMenu("rem", self)
        self.Menu["remLight"].addAction(self.Action["remLight"])
        self.Menu["Light"].addMenu(self.Menu["AddLight"])
        self.Menu["Light"].addMenu(self.Menu["editLight"])
        self.Menu["Light"].addMenu(self.Menu["remLight"])


        self.Menu["Edit"].addMenu(self.Menu["Object"])
        self.Menu["Edit"].addMenu(self.Menu["Camera"])
        self.Menu["Edit"].addMenu(self.Menu["Light"])
        ##

        self.Menu["Run"] = uiMenu("Run", self)
        self.Menu["Run"].addEvent(self.Action["Run"], "Run")
        self.Menu["Run"].addEvent(self.Action["Movie"], "Movie")

        self.Menu["Info"] = uiMenu("Info", self)

        self.menubar.addMenu(self.Menu["File"])
        self.menubar.addMenu(self.Menu["Tools"])
        self.menubar.addMenu(self.Menu["Edit"])
        self.menubar.addMenu(self.Menu["Run"])
        self.menubar.addMenu(self.Menu["Info"])

###########
    def createCentralMenu(self):
        self.central = QTabWidget(self)
        centralLayout = QGridLayout(self.central)

        self.Image = uiImage(self.ImagePath, self)
        self.central.addTab(self.Image, "Image")

        self.xml = QTextEdit(self)
        self.central.addTab(self.xml, "Xml")
        self.xml.setEnabled(False)

    def createLeftMenu(self):


        self.leftBar = QTabWidget(self)
        t = QGridLayout(self.leftBar)
        g = QGroupBox("Window", self.leftBar)
        hLayout = QGridLayout(self.leftBar)

        self.win_x = QLineEdit("0", self.leftBar)
        hLayout.addWidget(QLabel("X : "), 0, 0)
        hLayout.addWidget(self.win_x, 0, 1)

        self.win_y = QLineEdit("0", self.leftBar)
        hLayout.addWidget(QLabel("Y : "), 1, 0)
        hLayout.addWidget(self.win_y, 1, 1)
        g.setLayout(hLayout)
        t.addWidget(g, 0, 0)

        if (self.allImg):
            v = QVBoxLayout(self.leftBar)
            u = QGroupBox("Movie", self.leftBar)
            h = QHBoxLayout(self.leftBar)
            h.addWidget(QLabel("Current scene :"))
            self.scene = QComboBox(self.leftBar)
            i = 0
            while (i < len(self.allImg.Image)):
                self.scene.addItem(str(i))
                i += 1
            self.scene.connect(self.scene, SIGNAL("currentIndexChanged(int)"), self.Image.setImage)
            h.addWidget(self.scene)
            u.setLayout(h)
            v.addWidget(u)
            b = QPushButton("Mov", self.leftBar)
            b.connect(b, SIGNAL("clicked()"), self.runMovie)
            v.addWidget(b)
            t.addLayout(v, 1, 0)
            self.leftBar.hide()

        self.Run.setInfo(self.leftBar)
        t.addLayout(self.Run.gridLayout, 10, 0)

    def runMovie(self):
        i = 0
        while (i < len(self.allImg.Image)):
            self.Image.setImage(path=self.allImg.Image[i])
            i += 1
            time.sleep(1)

    def runRayTracer(self):
        if (self.Name):
            r = uiDialog(self)
            g = QGridLayout(r)
            self.setEnabled(False)
            t = QLabel("Calcul...", r)
            g.addWidget(t, 0, 0)
            r.show()
            u = self.Run
            u.e = True
            n = self.Name.split("/")
            k = n[len(n) - 1]
            name = k.split(".")[0]
            if (len(n)):
                n = "/".join(n)
            u.eLink = str(name + ".jpg")
            u.m = True
            u.run(self.Name)
            i = 0
            self.allImg = uiAllImage()
            print ("Le nom = " + name)
            print n + "/" + name + "/" + name + "-" + str(i) + ".jpg"
            try:
                fd = open("./" + name + "/" + name + "-" + str(i) + ".jpg")
                while (fd > 0):
                    self.allImg.addImage("./" + name + "/" + name + "-" + str(i) + ".jpg")
                    i += 1
                    fd.close
                    fd = open("./" + name + "/" + name + "-" + str(i) + ".jpg")
            except:
                i = 0
            self.Run.getInfo()
            self.Run.run(self.Name)
            print "Finish"
            try:
                self.Image.setImage(path=self.allImg.Image[0])
            except:
                i = 0
            self.setEnabled(True)
            r.reject()
            self.leftBar.setParent(None)
            self.createLeftMenu()
            self.leftBar.hide()
            self.leftBar.setParent(self)
            self.leftBar.setGeometry(0, self.menu_start, self.menu_width, self.height() - self.menu_start)
            self.leftBar.show()

    def insertText(self, Find, inser, s):
        i = s.find(Find)
        i += (s.find(">", i) - i) + 1
        if (i >= 0):
            result = s[:i] + inser + s[i:]
            QTextDocument(result)
            self.xml.setDocument(QTextDocument(result))
            return (result)
        return (None)

    def getInfo(self):
        self.setEnabled(True)
        u = self.q.getText()
        l = self.xml.toPlainText()
        e = ""
        r = ""
        s = str(l)
        if (self.q.Obj != "camera" and self.q.Obj != "light" and s.find("object") > 0):
            o = "<object"
        else:
            o = "<scene"
        i = s.find("scene")
        if (i < 0):
            e += "  <scene>\n"
            r = "  </scene>\n" + r
        if (self.q.Obj != "camera" and self.q.Obj != "light"):
            i = s.find("object")
            if (i < 0):
                e += "\n    <object>"
                r = "\n    </object>" + r
        u = e + u + r
        if (self.insertText(o, u, s) == None):
            if (self.insertText("<scene", u, s) == None):
                if (self.insertText("<window", u , s) == None):
                    self.xml.setDocument(QTextDocument(u))
        self.q.ok()

    def createRightMenu(self):
        self.rightBar = QTabWidget(self)
        self.rightGrid = QGridLayout(self.rightBar)

    def editLight(self):
        self.editObject("light")

    def editCamera(self):
        self.editObject("camera")

    def editPlan(self):
        self.editObject("plan")

    def editSphere(self):
        self.editObject("sphere")

    def editCylindre(self):
        self.editObject("cylindre")

    def editCone(self):
        self.editObject("cone")

    def editObject(self, find):
        new = editUi(self, str(self.xml.toPlainText()), find)

    def remLight(self):
        self.remObject("light")

    def remCamera(self):
        self.remObject("camera")

    def remPlan(self):
        self.remObject("plan")

    def remSphere(self):
        self.remObject("sphere")

    def remCylindre(self):
        self.remObject("cylindre")

    def remCone(self):
        self.remObject("cone")

    def remObject(self, find):
        new = editUi(self, str(self.xml.toPlainText()), find, t="remove")

    def addLight(self):
        self.addObject("light")

    def addCamera(self):
        self.addObject("camera")

    def addPlan(self):
        self.addObject("plan")

    def addSphere(self):
        self.addObject("sphere")

    def addCylindre(self):
        self.addObject("cylindre")

    def addCone(self):
        self.addObject("cone")

    def addCubetroue(self):
        self.addObject("cubetroue")

    def addTore(self):
        self.addObject("tore")

    def addPara(self):
        self.addObject("paraboloide")

    def addObject(self, s):
        self.setEnabled(False)
        self.q = uiAddObject(self, obj=s)
        self.q.init(self)
        if (self.Name == None):
            self.nameToFile()

    def newFile(self):
        new = newUi(self)
        self.Action["Save"].setEnabled(True)
        self.Action["SaveAs"].setEnabled(True)
        self.Action["Sphere"].setEnabled(True)
        self.Action["Cubetroue"].setEnabled(True)
        self.Action["Tore"].setEnabled(True)
        self.Action["Cylindre"].setEnabled(True)
        self.Action["Plan"].setEnabled(True)
        self.Action["Cone"].setEnabled(True)
        self.Action["Light"].setEnabled(True)
        self.Action["Camera"].setEnabled(True)
        self.Action["editSphere"].setEnabled(True)
        self.Action["editCylindre"].setEnabled(True)
        self.Action["editPlan"].setEnabled(True)
        self.Action["editCone"].setEnabled(True)
        self.Action["editLight"].setEnabled(True)
        self.Action["editCamera"].setEnabled(True)
        self.Action["remSphere"].setEnabled(True)
        self.Action["remCylindre"].setEnabled(True)
        self.Action["remPlan"].setEnabled(True)
        self.Action["remCone"].setEnabled(True)
        self.Action["remLight"].setEnabled(True)
        self.Action["remCamera"].setEnabled(True)
        self.xml.setEnabled(True)
        new.init()

    def openFile(self):
        self.setEnabled(False)
        fname = QFileDialog.getOpenFileName(self, 'Open file',
                                                  '.')
        link = str(fname)
        if (link):
            self.Action["Save"].setEnabled(True)
            self.Action["SaveAs"].setEnabled(True)
            self.Action["Tore"].setEnabled(True)
            self.Action["Cubetroue"].setEnabled(True)
            self.Action["Sphere"].setEnabled(True)
            self.Action["Cylindre"].setEnabled(True)
            self.Action["Plan"].setEnabled(True)
            self.Action["Cone"].setEnabled(True)
            self.Action["Light"].setEnabled(True)
            self.Action["Camera"].setEnabled(True)
            self.Action["editSphere"].setEnabled(True)
            self.Action["editCylindre"].setEnabled(True)
            self.Action["editPlan"].setEnabled(True)
            self.Action["editCone"].setEnabled(True)
            self.Action["editLight"].setEnabled(True)
            self.Action["editCamera"].setEnabled(True)
            self.Action["remSphere"].setEnabled(True)
            self.Action["remCylindre"].setEnabled(True)
            self.Action["remPlan"].setEnabled(True)
            self.Action["remCone"].setEnabled(True)
            self.Action["remLight"].setEnabled(True)
            self.Action["remCamera"].setEnabled(True)

            x = file(link, "r")
            r = x.read()
            self.Name = link
            i = r.find(">", r.find("window"))
            if (i > 0):
                self.head = r[:(i + 1)]
                a = self.head.find("=", self.head.find("x"))
                if (a > 0):
                    self.win_x.setText(self.head[(a + 1):self.head.find(" ", a)])
                a = self.head.find("=", self.head.find("y"))
                if (a > 0):
                    self.win_y.setText(self.head[(a + 1):self.head.find(" ", a)])
            i += 1
            while (i < len(r) and r[i] != '<'):
                i += 1
            j = r.find("</window")
            if (i > 0):
                self.foot = r[(j):]
            self.xml.setDocument(QTextDocument(r[i:j]))
            self.xml.setDocumentTitle(fname)
            self.xml.setEnabled(True)
            x.close()
        self.setEnabled(True)

    def getImage(self):
        fname = QFileDialog.getOpenFileName(self, 'Open file',
                                                  '.')
        link = str(fname)
        self.ImagePath = link
        self.setImage()

    def setImage(self):
        self.Image.setPixmap(QPixmap(self.ImagePath))
        self.central.show()

    def saveFile(self):
        if (self.Name == None):
            self.nameToFile()
        l = self.xml.toPlainText()
        s = str(l)
        files = file(self.Name, 'w')
        files.write("<window x=" + (self.win_x.displayText()) + " y=" + self.win_y.displayText() + ">\n"
                    + str(s) +
                    "\n</window>")
        files.close()

    def saveToFile(self):
        self.nameToFile()
        self.saveFile()

    def nameToFile(self):
        self.Name = QFileDialog.getSaveFileName(self)
        if (('.xml' in self.Name) == False):
            self.Name += ".xml"

    def createXmlFile(self):
        self.xml.init(self.Name)

    def leftMenu(self):
        s.elf.leftBar.show()

    def rightMenu(self):
        self.rightBar.show()

    def creationMovie(self):
        new = Ui_edit_movie(self)
        new.init(self, self.Name, ("<window x=" + (self.win_x.displayText()) +
                                   " y=" + self.win_y.displayText() + ">\n"))

#############################
