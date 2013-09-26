
///////////////////////
// SOCKET.IO
///////////////////////

function	update(map, data) {
    var objects = data.objects;
    var players = data.players;
    var bombs = data.bombs;
    for (var i = 0; i < objects.length; i++) {
	map.updateObject(objects[i]);
    }
    for (var i = 0; i < players.length; i++) {
	map.updatePlayer(players[i]);
    }
    for (var i = 0; i < bombs.length; i++) {
	map.updateBomb(bombs[i]);
    }
}

////////////////////////
// MODULE EXPORT
////////////////////////

exports.update = update;
