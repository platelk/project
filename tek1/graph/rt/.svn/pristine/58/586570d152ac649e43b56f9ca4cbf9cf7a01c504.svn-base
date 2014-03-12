#!/usr/bin/python2.7

#Made by Vink

import sys
from xml.dom import minidom
from ui.ui import *
from ui.obj import *

# Importation des classes de Qt necessaires.

try:
    from PyQt4.QtCore import *  # Moteur controle Qt
    from PyQt4.QtGui import *   # IHM Qt
except:
    import time                 # Gestion heures systeme
    for i in range(1, 11):
        print ("PyQt is not install - check in (%d/10)", i)
        time.sleep(5)
        sys.exit(1)

def main():

    app = QApplication(sys.argv)
    MainWindow = uiMainWindow(1400, 900)
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()
