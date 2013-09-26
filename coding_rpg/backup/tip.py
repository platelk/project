#! /usr/bin/python3.2

import xml.dom.minidom
import sys
class Tip:
    def __init__(self, name, content, cost):
        self.content = content
        self.name = name
        self.cost = cost

    def print_tip(self):
        return ("==" + str(self.name) + "====[" + str(self.cost) + "]=========\n\t" + str(self.content) + "\n")


class Tips:
    def __init__(self, tips_file = "tips.xml"):
        try:
            self.dom = xml.dom.minidom.parse(tips_file);
        except:
            sys.stdout.write("Error: bad xml file\n")
            sys.exit(1)
        self.current_node = None
        self.get_tips()
        self.my_tips = list()

    def list_tips(self):
        if (self.tip_list != None):
            num = 0
            message = ""
            for i in self.tip_list:
                message += str(num) + ". " + str(i.name) + " cost: " + str(i.cost) + "\n"
                num += 1
            return (message)

    def list_my_tips(self):
        message = ""
        if (self.tip_list != None):
            for i in self.my_tips:
                message += i.print_tip()
            return (message)

    def buy_tip(self, id_tip):
        if (self.tip_list != None):
            try:
                self.tip_list[int(id_tip)].print_tip()
                self.my_tips.append(self.tip_list[int(id_tip)])
                self.tip_list.pop(int(id_tip))
                return ("Success")
            except:
                return ("Error: id_tip do not exist\n")
        return ("No tips avaible")

    def getRootElement(self):
        if (self.current_node == None):
            self.current_node = self.dom.documentElement
        return (self.current_node)

    def get_tips(self):
        self.tip_list = list()
        for tip in self.getRootElement().getElementsByTagName("tip"):
            try:
                name = self.getText(tip.getElementsByTagName("name")[0])
                content = self.getText(tip.getElementsByTagName("content")[0])
                cost = self.getText(tip.getElementsByTagName("cost")[0])
                t = Tip(name, content, cost)
            except:
                sys.stdout.write("Error: missing tag (name, content or cost)\n")
            self.tip_list.append(t)
        return (self.tip_list)

    def getText(self, node):
        return (node.childNodes[0].nodeValue)
