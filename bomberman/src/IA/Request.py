#! /bin/python3.3

import  Trame
from    Factory import *

def     id_network(factory, ia, trame):
    print("[INFO]: id_network")
    try:
        ia.id_network = int(trame.args)
    except ValueError:
        print("[Error]: not a integer")

def     id_player(factory, ia, trame):
    print("[INFO]: id_player")
    try:
        ia.ia_id = int(trame.args)
        print("MY ID is ", ia.ia_id)
    except:
        print("[Error]: not a integer")

def     start(Factory, ia, trame):
    print("[INFO]: game start")
    ia.alive = True

def     nextstep(Factory, ia, trame):
    ia.bot.nextstep = True;

def     map(factory, ia, trame):
    print("[INFO]: action map ")
    elms = trame.args.split("|")
    objects = []
    for i in elms:
        if i != "":
            try:
                ret = factory.create(i)
            except SyntaxError:
                print("[Error]: obj bad format")

            else:
                if ret != None:
                    objects.append(ret)
                    if ret.name == "bomb":
                        ia.addBomb(ret)
    ia.core.loadMap(objects)
    print("[nbr objects] = ", len(ia.core.map.gameObjects));

def     all_player(factory, ia, trame):
    elms = trame.args.split("|")
    print("[INFO]: action all_player", trame.args)
    for i in elms:
        if i != "":
            try:
                ret = factory.create(i)
                if ret.id == ia.ia_id:
                    ia.updateIA(ret)
                else:
                    if ret != None:
                        ia.core.addPlayer(ret)
            except SyntaxError:
                print("[Error]: user bad format")
    print("[nbr players] = ", len(ia.core.players));

def     player(factory, ia, trame):
    print("[INFO]: action player", trame)
    found = False
    ret = factory.create(trame.args)
    if ret.id == ia.ia_id:
        ia.updateIA(ret)
        found = True
    else:
        for i in ia.core.players:
            if i.id == ret.id:
                ia.core.players[ia.core.players.index(i)] = ret
                found = True
                break
    if found == False:
        ia.core.players.append(ret);
    
def     tile(factory, ia, trame):
    print("[INFO]: action tile")
    ret = factory.create(trame.args)
    ia.core.map.setTile(ret.id, ret)
    if ret.name == "bomb":
        ia.addBomb(ret)

def     die(factory, ia, trame):
    print("[INFO]: action die")
    if int(trame.target_id) == ia.ia_id:
        ia.alive = False
    else:
        if delObject(int(trame.target_id)) == False:
            removePlayer(int(trame.target_id))

def     alive(factory, ia, trame):
    print("[INFO]: action alive")
    ia.alive = True

def     game_start(factory, ia, trame):
    print("[INFO]: action start")
    ia.is_running = True

def     game_stop(factory, ia, trame):
    print("[INFO]: action stop")
    ia.is_running = False

def     move(factory, ia, trame):
    print("[INFO]: action move")
    try:
        elms = trame.args.split("|")
        print(elms)
        if int(elms[0]) == ia.ia_id:
            ia.pos = (int(elms[1]), int(elms[2]), int(elms[3]))
            ia.dir = (int(elms[4]), int(elms[5]), int(elms[6]))
        else:
            for i in ia.core.players:
                if i.id == int(elms[0]):
                    position = i.getComponent("position")
                    position.x = int(elms[1])
                    position.y = int(elms[2])
                    position.z = int(elms[3])
                    position.dx = int(elms[4])
                    position.dy = int(elms[5])
                    position.dz = int(elms[6])
                    break;
            raise IndexError("player doesn't exist")
    except (SyntaxError, NameError):
        print("[Error]: missing value or bad formated")
    except IndexError:
        print("[Error]: player doesn't exist")

