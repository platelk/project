#! /bin/python3.3

PLAYER = 0
ITEM = 1
BOMBE = 2
DECOR = 3

COLLIDER = "collider"

class   Map:
    def __init__(self, objects):
        self.gameObjects = []
        self.collide = []
        self.bomb = []
        for i in objects:
            if i.haveThisComponent("colider"):
                self.collide.append(i)
            if i.name == "bomb":
                self.bomb.append(i)
            self.gameObjects.append(i)

    def setTile(self, id, obj):
        found = False
        for i in self.gameObjects:
            if i.id == id:
                self.gameObjects[self.gameObjects.index(i)] = obj
                found = True
                break
        if found == False:
            self.gameObjects.append(obj)
        if obj.haveThisComponent("colider"):
            found = False
            for i in self.collide:
                if i.id == id:
                    self.collide[self.collide.index(i)] = obj
                    break
            if found == False:
                self.collide.append(obj)
        if obj.name == "bomb":
            found = False
            for i in self.bomb:
                if i.id == id:
                    self.bomb[self.bomb.index(i)] = obj
                    break
            if found == False:
                self.bomb.append(obj)
        
    def getTile(self, id):
        for i in self.gameObjects:
            if i.id == id:
                return (i)
        raise IndexError("not in map")

    def delObject(self, id):
        for i in self.gameObjects:
            if i.id == id:
                self.gameObjects.remove(i)
                return (True)
        return (False)
