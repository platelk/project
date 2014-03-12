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

class   newUi(uiDialog):
    def __init__(self, Window):
        super(newUi, self).__init__(Window)
        self.Parent = Window

    def init(self):
        self.gridLayout = QGridLayout(self)
        self.Coor = QGroupBox("File", self)
        hLayout = QHBoxLayout(self)

        self.fileName = QLineEdit("Default", self)
        hLayout.addWidget(QLabel("Name"))
        hLayout.addWidget(self.fileName)

        self.Coor.setLayout(hLayout)
        self.gridLayout.addWidget(self.Coor, 0, 1)

        self.Coor = QGroupBox("Window", self)
        hLayout = QHBoxLayout(self)

        self.winX = QLineEdit("500", self)
        hLayout.addWidget(QLabel("Size x :"))
        hLayout.addWidget(self.winX)
        self.winY = QLineEdit("500", self)
        hLayout.addWidget(QLabel("Size y :"))
        hLayout.addWidget(self.winY)

        self.Coor.setLayout(hLayout)
        self.gridLayout.addWidget(self.Coor, 1, 1)

        hLayout = QHBoxLayout(self)
        act = QPushButton("Ok", self)
        act.connect(act, SIGNAL("clicked()"), self.getText)
        hLayout.addWidget(act)
        act = QPushButton("Quit", self)
        act.connect(act, SIGNAL("clicked()"), self.quit)
        hLayout.addWidget(act)
        self.gridLayout.addLayout(hLayout, 10, 1)
        self.show()

    def getText(self):
        self.Parent.Name = self.fileName.displayText()
        self.Parent.win_x.setText(self.winX.displayText())
        self.Parent.win_y.setText(self.winY.displayText())

        s = "<scene>\n<object>\n</object>\n</scene>\n"
        self.Parent.xml.setDocument(QTextDocument(s))
        self.quit()

    def quit(self):
        self.Parent.setEnabled(True)
        self.reject()
