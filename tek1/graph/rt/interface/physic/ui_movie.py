#!/usr/bin/python2.7
#
#by ozouf_h

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
    def __init__(self, Window=None):
        super(Ui_edit_movie, self).__init__(Window)
        self.GridLay = QGridLayout(self)
        self.Coor = QGroupBox("Key images", self)
        hLayout = QHBoxLayout(self)
        act = QPushButton("Add key", self)
#        act.connect(act, SIGNAL("clicked()") self.Parent.add_elm)
        hLayout.addWidget(act)
        act = QPushButton("Quit", self)
        act.connect(act, SIGNAL("clicked()"), self.quit)
        hLayout.addWidget(act)
        self.Parent = Window
        self.GridLay.addLayout(hLayout, 10, 1)
        self.show()

    def quit(self):
        if (self.Parent):
            self.Parent.setEnabled(True)
        self.reject()
