#! /bin/python3.3

import  Core
import  Factory
import  Request
import  Trame
import  IA

objects_serialized = []
players_serialized = []
objects_serialized.append("GO:5:decor:1:4:23:{CP:4:life:9:{i:3:100}}")
objects_serialized.append("GO:5:decor:1:5:23:{CP:4:life:9:{i:3:100}}")
objects_serialized.append("GO:5:decor:1:6:23:{CP:4:life:9:{i:3:100}}")

pos = "CP:8:position:37:{i:1:0;i:1:0;i:1:0;i:1:0;i:1:0;i:1:0}"
col = "CP:7:colider:26:{i:1:0;i:1:0;i:1:0;i:2:20}"
objects_serialized.append("GO:5:decor:1:7:99:{" + pos + ";" + col + "}")

pos = "CP:8:position:37:{i:1:0;i:1:0;i:1:0;i:1:0;i:1:0;i:1:0}"
col = "CP:7:colider:26:{i:1:0;i:1:0;i:1:0;i:2:20}"
life = "CP:4:life:9:{i:3:100}"
tb = "CP:10:throw_bomb:2:{}"
mv = "CP:4:move:2:{}"
psize = 1 + len(pos) + 1 + len(col) + 1 + len(life) + 1 + len(tb) + 1 + len(mv) + 1
players_serialized.append("GO:6:player:1:9:" + str(psize) + ":{" + pos + ";" + tb + ";" + life + ";" + col + ";" + mv + "}")
players_serialized.append("GO:6:player:2:10:" + str(psize) + ":{" + pos + ";" + tb + ";" + life + ";" + col + ";" + mv + "}")

f = Factory.Factory()

objects = []
for i in objects_serialized:
    print("preparing serializing [" + i[:80] + "...]")
    objects.append(f.create(i))

c = Core.Core()

c.loadMap(objects)


for i in players_serialized:
    print("preparinf serializing [" + i[:80] + "...]")
    c.addPlayer(f.create(i))

print(c.map.getTile(4))

c.removePlayer(9)
c.removePlayer(10)
print("removing OK")
mepos = "CP:8:position:39:{i:2:51;i:2:51;i:1:1;i:1:1;i:1:1;i:1:1}"
mepsize = 1 + len(mepos) + 1 + len(col) + 1 + len(life) + 1 + len(tb) + 1 + len(mv) + 1
me_serialized = "GO:6:player:1:1:" + str(mepsize) + ":{" + mepos + ";" + tb + ";" + life + ";" + col + ";" + mv + "}"

me = IA.IA(None, c, (0, 0, 0), (0, 0, 0), 1)
print("IA creation OK")
print("mypos",me.getMyPos())
me.updateIA(f.create(me_serialized))
print("UpdateIAplayer info OK")
print("colide: " + str(me.noCollision((40, 0, 0))))
print("range: " + str(me.range((0,0,0), (50,0,0))))
print("headfor", me.headFor((0,0,0), (-50,0,0)))
print("mypos",me.getMyPos())
print("mydir", me.getMyDir())
print("directions", me.getPossibleDirection())
0.0, 30.0, 60.0, 90.0, 120.0, 150.0, 180.0, 210.0, 240.0, 270.0, 300.0, 330.0
me.move(0)
me.move(30)
me.move(60)
me.move(90)
me.move(120)
me.move(150)
me.move(180)
me.move(210)
me.move(240)
me.move(270)
me.move(300)
me.move(330)

print("##################TEST des trames input#############################")

print("test MAP:")
obj = []
obj.append("GO:5:decor:2:50:2:{}")
obj.append("GO:5:decor:2:51:2:{}")
obj.append("GO:5:decor:2:52:2:{}")
obj.append("GO:5:decor:2:53:2:{}")
map_request = "1:1;3:map;6:player;0:;0:;" + obj[0] + "|" + obj[1] + "|" + obj[2] + "|" + obj[3]
map_request_tr = Trame.Trame([map_request])
Request.map(f, me, map_request_tr)
for i in me.core.map.gameObjects:
    print("obj id: ", i.id, "is in map")


print("\ntest ALL_PLAYER:")
tpos = "CP:8:position:37:{i:1:0;i:1:0;i:1:0;i:1:0;i:1:0;i:1:0}"
tcol = "CP:7:colider:26:{i:1:0;i:1:0;i:1:0;i:2:20}"
tlife = "CP:4:life:9:{i:3:100}"
ttb = "CP:10:throw_bomb:2:{}"
tmv = "CP:4:move:2:{}"
tpsize = 1 + len(tpos) + 1 + len(tcol) + 1 + len(tlife) + 1 + len(ttb) + 1 + len(tmv) + 1

t_players = []
t_players.append("GO:6:player:1:0:" + str(tpsize) + ":{" + tpos + ";" + ttb + ";" + tlife + ";" + tcol + ";" + mv + "}")
t_players.append("GO:6:player:1:3:" + str(tpsize) + ":{" + tpos + ";" + ttb + ";" + tlife + ";" + tcol + ";" + mv + "}")
t_players.append("GO:6:player:1:2:" + str(tpsize) + ":{" + tpos + ";" + ttb + ";" + tlife + ";" + tcol + ";" + mv + "}")
all_player_request = "1:1;10:all_player;6:player;0:;0:;" + t_players[0] + "|" + t_players[1] + "|" + t_players[2]
all_player_request_tr = Trame.Trame([all_player_request])
Request.all_player(f, me, all_player_request_tr)
for i in me.core.players:
    print("player id:", i.id, "is in players list(core)")

print("\ntest PLAYER:")
for i in me.core.players:
    lif = i.getComponent("life")
    print("player id:", i.id, "life:", lif.life)
ttlife = "CP:4:life:9:{i:3:110}"
new_player = "GO:6:player:1:0:" + str(tpsize) + ":{" + tpos + ";" + ttb + ";" + ttlife + ";" + tcol + ";" + mv + "}"
player_request = "1:1;6:player;6:player;0:;0:;" + new_player
player_request_tr = Trame.Trame([player_request])
Request.player(f, me, player_request_tr)
for i in me.core.players:
    lif = i.getComponent("life")
    print("player id:", i.id, "life:", lif.life)

print("\ntest TILE:")
for i in me.core.map.gameObjects:
    try:
        dt = i.getComponent("life")
    except IndexError:
        print("obj id:", i.id, "can't find life")
    else:
        print("obj id:", i.id, "life:", dt.life)
tile = "GO:5:decor:2:51:23:{CP:4:life:9:{i:3:140}}"
tile_request = "1:1;4:tile;6:player;0:;0:;" + tile
tile_request_tr = Trame.Trame([tile_request])
Request.tile(f, me, tile_request_tr)
for i in me.core.map.gameObjects:
    try:
        dt = i.getComponent("life")
    except IndexError:
        print("obj id:", i.id, "can't find life")
    else:
        print("obj id:", i.id, "life:", dt.life)

print("\ntest MOVE:")
print(me.pos, me.dir)
move_r = str(me.ia_id) + "|50|10|0|0|0|0"
move_request = "1:1;4:move;6:player;0:;0:;" + move_r
move_request_tr = Trame.Trame([move_request])
Request.move(f, me, move_request_tr)
print(me.pos, me.dir)

print("ALL REQUEST ARE TESTED")
