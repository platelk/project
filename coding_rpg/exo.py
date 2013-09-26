#! /bin/python3.2

import xml.etree.ElementTree as ET
import os

class Exo:
    def __init__(self, langage, id):
        self.langage = langage
        self.id = id
        self.path = "./ressources/" + langage + "/" + "exo_" + str(id) + ".xml"
        try:
            root = ET.parse(self.path)
        except:
            sys.stderr.write("Error: " + path + " not found or bad format\n")
            return (None)
        try:
            root = root.getroot()
            self.name = root.findall("./name")[0].text
            self.subject = root.findall("./subject")[0].text
            self.credit = root.findall("./credit")[0].text
            self.output_file = root.findall("./test/output_file")[0].text
            try:
                self.params = [i.text for i in root.findall("./test/params/param")]
            except:
                self.params = None
            try:
                self.achievement = [i.text for i in root.findall("./achievement/name")]
            except:
                self.achievement = None
        except:
            sys.stderr.write("Error: " + path + " bad format\n")
            return (None)

    def get_id(self):
        return (self.id)

    def get_subject(self):
        return (self.subject)

    def get_name(self):
        return (self.name)

    def get_credit(self):
        return (self.credit)

    def get_achievement(self):
        return (self.achievement)

    def get_output_file(self):
        print(self.output_file)
        return (self.output_file)

    def get_reference(self):
        with open(self.output_file) as fp:
            s = fp.read()
            fp.close()
            return(s)
    def get_params(self):
        s = ""
        for i in self.params:
            s += i + "::"
        return (s)
