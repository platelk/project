#! /bin/python3.3

import  time

class   Timer:
    def __init__(self, action_type, timeout, callback, args):
        if action_type != "after" and action_type != "each":
            raise NotImplementedError
        self.type = action_type
        self.timeout = timeout
        self.callback = callback
        self.args = args
        self.last_time = time.time()
        
    def runAction(self):
        self.callback(*self.args)

    def update(self):
        if self.type == "after":
            if self.isFinished() == True:
                self.runAction()
        elif self.type == "each":
            self.runAction
        
    def isFinished(self):
        if self.last_time + self.timeout < time.time():
            return (True)
        return (False)

class   TimerPool:
    def __init__(self):
        self.nbr_timer = 0
        self.timers = []

    def addTimer(self, name, action_type, timeout, callback, args):
        new_timer = Timer(action_type, timeout, callback, args)
        self.timers.append((name, new_timer))
        self.nbr_timer += 1

    def delTimer(self, name):
        if self.exist(name):
            for t in self.timers:
                if t[0] == name:
                    self.timers.remove(t)
            self.nbr_timer -= 1
        else:
            raise IndexError

    def update(self):
        for t in self.timers:
            t[1].update()
            if t[1].isFinished() == True:
                self.timers.remove(t)

    def get(self, name):
        for t in self.timers:
            if t[0] == name:
                return (t[0])
        raise IndexError

    def exist(self, name):
        for t in self.timers:
            if t[0] == name:
                return (True)
        return (False)

    def getTimeout(self, name):
        t = self.get(name)
        return (time.time() - (t.last_time + t.timeout))
            
