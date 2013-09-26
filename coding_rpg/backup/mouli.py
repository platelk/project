#! /usr/bin/python3.2

import sys
import time
import xml.dom.minidom
from difflib import *

nbr_exo = 7
exo_config_file = "exo_config.xml"

class Exo:
    def __init__(self, section, name, num_exo, config_file = exo_config_file):
        self.name = name
        self.exoId = num_exo
        self.begin = time.time()
        self.nbr_try = 0
        self.config_file = config_file
        self.section = section
        self.current_node = None
        try:
            self.dom = xml.dom.minidom.parse(self.config_file)
        except:
            sys.stdout.write("Error : bad exo file\n")
            return (None)
#        try:
#        except:
#            sys.stdout.write("Error : bad section name\n")
#            sys.exit(1)
        for i in self.getRootElement().getElementsByTagName(self.section):
            self.name = self.getText(i.getElementsByTagName("path")[self.exoId])
            try:
                self.file_ref = open(self.name + '/ref', 'r')
                self.file_subject = open(self.name + '/subject', 'r')
                self.params = open(self.name + '/params', 'r').readlines()
            except:
                sys.stdout.write("Error: " + self.name + " not found.\n")
                return (None)

    def newSubject(self, section, num_exo):
        self.section = section
        self.exoId = num_exo
        print ("getting new subjet...")
        print(section)
        print(num_exo)
        for i in self.getRootElement().getElementsByTagName(self.section):
            self.name = self.getText(i.getElementsByTagName("path")[self.exoId])
            try:
                self.file_ref = open(self.name + '/ref', 'r')
                self.file_subject = open(self.name + '/subject', 'r')
                self.params = open(self.name + '/params', 'r').readlines()
                print("ok !")
            except:
                sys.stdout.write("Error: " + self.name + " not found.\n")
                return (None)
    def get_subject(self):
        message = ""
        for line in self.file_subject:
            message += line
        return (message)

    def getText(self, node):
        return (node.childNodes[0].nodeValue)

    def getRootElement(self):
        if (self.current_node == None):
            self.current_node = self.dom.documentElement
        return (self.current_node)

    def get_params(self):
        return (self.params)

    def get_name(self):
        return (self.name)

    def check(self, content):
        self.nbr_try += 1
        print(self.file_ref.readlines())
        if (content == "".join(self.file_ref.readlines())):
            res = time.time() - self.begin
            x = time.localtime(res)
            self.time = str(x.tm_hour - 1) + " hours " + str(x.tm_min) + " minutes and " + str(x.tm_sec) + " seconds"
            return (True)
        else:
            return (False)

    def print_res(self):
        return (self.name + " solved in " + self.time + ".\n")

    def get_params(self):
        return (self.params)
