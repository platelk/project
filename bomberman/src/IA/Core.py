#! /bin/python3.3

import  Map
import  Timer
import  Factory

class   Core:
    def __init__(self):
        self.game_is_started = None
        self.map = None
        self.players = []
        self.timers = Timer.TimerPool()
        self.storage = {}

    def loadMap(self, objects):
        self.map = Map.Map(objects)

    def addPlayer(self, gameObject):
        if gameObject.haveThisComponent("life") and \
                gameObject.haveThisComponent("position") and \
                gameObject.haveThisComponent("move") and \
                gameObject.haveThisComponent("throw_bomb") and \
                gameObject.haveThisComponent("colider"):
            self.players.append(gameObject)
        else:
            raise SyntaxError("missing component")

    def removePlayer(self, id):
        found = False
        for p in self.players:
            if p.id == id:
                self.players.remove(p)
                found = True
                break
        if found == False:
            return (False)
        return (True)
