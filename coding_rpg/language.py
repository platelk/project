#! /bin/python3.2

import xml.etree.ElementTree as ET
import sys
from exo import *

NO_INSTANCED = 2
EXIT_FAILURE = 1
EXIT_SUCCESS = 0

class Language:
    def __init__(self, name, language_file, id=0):
        self.name = name
        self.lvl = 0
        self.points = 0
        self.tips = list()
        self.my_tips = list()
        self.achievement = list()
        self.lesson = list()
        self.current_exo = Exo(name, id)
        self.language_path = "./ressources/" + name + "/"
        self.lessons_path = "./ressources/" + name + "/lessons/"
        self.config_path = "./ressources/" + name + "/" + language_file
        try:
            root = ET.parse(self.config_path)
        except:
            sys.stderr.write("Error: " + self.config_path + " not found or bad format\n")
            return (None)
        try:
            root = root.getroot()
            for tip in root.findall("./tips/tip"):
                name = tip.findall("./name")[0].text
                content = tip.findall("./content")[0].text
                cost = int(tip.findall("./cost")[0].text)
                self.tips.append({'name': name, 'content': content, 'cost': cost})
                for i in root.findall("./lessons/lesson"):
                    try:
                        lesson_name = i.findall("./name")[0].text
                        lesson_content = "".join(open(self.lessons_path + i.findall("./filename")[0].text).readlines())
                        for_exo = int(i.findall("./for_exo")[0].text)
                        self.lesson.append({'name':lesson_name, 'content': lesson_content, 'for_exo': for_exo})
                    except:
                        sys.stderr.write("Error: " + i + " file not found or bad formated\n")
        except:
            sys.stderr.write("Error: " + config_path + " bad format\n")
            return (None)

    def refresh_exo(self):
        if (self.current_exo is None):
            self.current_exo = Exo(self.name, self.lvl)
            if (self.current_exo is not None):
                return (EXIT_SUCCESS, "chargement done" + str(self.lvl))
            else:
                return (NO_INSTANCED, "exo is not load")

    def next_exo(self):
        if (self.current_exo is not None):
            self.current_exo = Exo(self.name, self.lvl + 1)
            self.lvl += 1
            self.points += current_exo.get_credit()
            self.check_achievement()
            return (EXIT_SUCCESS, "chargement done lvl: " + str(self.lvl))
        else:
            self.current_exo = Exo(self.name, self.lvl)
            if (self.current_exo is not None):
                return (EXIT_SUCCESS, "chargement done" + str(self.lvl))
            else:
                return (NO_INSTANCED, "exo is not load")

    def prev_exo(self):
        if (self.current_exo is not None):
            self.current_exo = Exo(self.name, self.lvl - 1)
            self.lvl -= 1
            return (EXIT_SUCCESS, "chargement done lvl: " + str(self.lvl))
        else:
            self.current_exo = Exo(self.name, self.lvl)
            if (self.current_exo is not None):
                return (EXIT_SUCCESS, "chargement done" + str(self.lvl))
            else:
                return (NO_INSTANCED, "exo is not load")


    def get_points(self):
        return (EXIT_SUCCESS, self.points)


    def get_credit(self):
        if (self.current_exo is not None):
            return (EXIT_SUCCESS, self.current_exo.get_credit())
        else:
            return (NO_INSTANCED, "exo is not load")

    def get_lvl(self):
        return (EXIT_SUCCESS, self.lvl)

    def check_achievement(self):
        if (self.current_exo is not None):
            if (self.current_exo.get_achievement() is not None):
                self.achievement.extend(self.current_exo.get_achievement())
                return (EXIT_SUCCESS, "check done")
            return (EXIT_SUCCESS, "check done")
        return (NO_INSTANCED, "exo is not load")

    def check_exo(self, content):
        print("Checking exo...")
        if (self.current_exo is not None):
            print(content.replace("??", "\n"))
            if (str(content).replace("??", "\n") == self.current_exo.get_reference()):
                print("Congratulation")
                self.next_exo()
                return (EXIT_SUCCESS, "Congratulation")
            else:
                print("Error")
                return (EXIT_FAILURE, "Outputs are differents")
        else:
            return (NO_INSTANCED, "exo is not load")

    def get_name(self):
        return (EXIT_SUCCESS, self.name)

    def get_params(self):
        if (self.current_exo is not None):
            if (self.current_exo.get_params() is not None):
                return (EXIT_SUCCESS, self.current_exo.get_params())
            else:
                return (EXIT_SUCCESS, "")
        else:
            return (NO_INSTANCED, "exo is not load")

    def list_tips(self):
        text = ""
        for i, t in enumerate(self.tips):
            text += str(i) + ".\t" + t['name'] + "cost: " + t['cost'] + "\n"
        return (EXIT_SUCCESS, text)

    def list_my_tips(self):
        text = ""
        if (len(self.my_tips) == 0):
            return (EXIT_SUCCESS, "you don't have tips\n")
        for i, t in enumerate(self.my_tips):
            text += str(i) + ".\t" + t['name'] + "\n"
        return (EXIT_SUCCESS, text)

    def get_tips(self, id):
        try:
            text = self.my_tips[id]['name'] + ":\t" + self.my_tips[id]['content'] + "\n"
            return (EXIT_SUCCESS, text)
        except:
            return (EXIT_FAILURE, "id is out of range\n")

    def buy_tips(self, id):
        try:
            self.my_tips.append(self.tips.pop(id))
            try:
                return (EXIT_SUCCESS, int(self.my_tips[-1:][0]['cost']))
            except:
                return (EXIT_FAILURE, "no more tips available\n")
        except:
            return (EXIT_FAILURE, "id is out of range\n")

    def get_current_exo(self):
        if (self.current_exo is not None):
            text = "exo number " + str(self.current_exo.get_id()) + "\n"
            text += "name:\t" + self.current_exo.get_name() + "\n"
            text += "subject:\n" + self.current_exo.get_subject() + "\n"
            return (EXIT_SUCCESS, text)
        return (EXIT_FAILURE, "exo is not load\n")

    def get_lesson(self, id):
        if (self.current_exo is not None):
            try:
                if (self.lvl >= self.lesson[int(id)]['for_exo']):
                    text = self.lesson[int(id)]['name'] + "\n"
                    text += self.lesson[int(id)]['content'] + "\n"
                    return (EXIT_SUCCESS, text)
                return (EXIT_FAILURE, "access denied for this lesson\n")
            except:
                return (EXIT_FAILURE, "id is out of range\n")
        return (NO_INSTANCED, "exo is not load\n")

    def list_lesson(self):
        if (self.current_exo is not None):
            text = ""
            for i, l in enumerate(self.lesson):
                if (self.lvl >= l['for_exo']):
                    text += str(i) + ". " + l['name'] + "(UNLOCK)\n"
                else:
                    text += "[" + str(i) + ". " + l['name'] + "](LOCK)\n"
            return (EXIT_SUCCESS, text)
        return (NO_INSTANCED, "exo is not load\n")
