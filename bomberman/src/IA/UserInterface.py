#! /bin/python3.3

import  random

"""
IA programming
"""
"""
def     setOffensiveGoal(actions):
    act = random.randint(1, 10)
    if act == 1:# and actions.getNbrBombs() > 0: 
        actions.throwBomb(random.choice(actions.getPossibleDirections()), random.randint(10, 60))
    else:
        i = 0;
        while True:
            if i < 50:
                print("in looop1")
                direction = random.choice(actions.getPossibleDirections())
#                if actions.noCollision(actions.dirToPos(actions.getMyPos(), direction)) == True:
                actions.move(direction)
                break
                i += 1
            else:
                break

def     setDefensiveGoal(actions):
    i = 0
    while True:
        if i < 50:
            print("in looop2")
            direction = random.choice(actions.getPossibleDirections())
#            if actions.noCollision(actions.dirToPos(actions.getMyPos(), direction)) == True:
            actions.move(direction)
            break
            i += 1
        else:
            break

def     setNewGoal(actions):
    if actions.inExplosion(actions.getMyPos(), actions.getMyRadius()) == True:
        setDefensiveGoal(actions)
    else:
        setOffensiveGoal(actions)

"""
def     init(actions):
    print("init OK")
    actions.storeData('direction', 0)
    actions.storeData('throw', 0)

def run(actions):
    directions = actions.getPossibleDirections()
    idx = actions.getData('direction')
    direction = directions[idx]
    pos = actions.dirToPos(actions.getMyPos(), direction)
    if actions.noCollision(pos) == False:
        if idx == 12:
            idx = -1
        actions.storeData('direction', idx + 1)
    idx = actions.getData('direction')
    nbr = actions.getData('throw')
    
    if nbr >= 15:
        actions.throwBomb(direction, 3)
        actions.storeData('throw', 0)
    else:
        actions.move(directions[idx])
        actions.storeData('throw', nbr + 1)    
