/////////////////////////////
// CONNECT
/////////////////////////////

CRLF = "\r\n"

function	sendMap(sock, map) {
    sock.write("1:0;3:map;6:player;0:;0:;0:" + CRLF);
}

function	sendIdNetwork(sock) {
    sock.write("1:0;9:connexion;6:player;0:;0:;1:0" + CRLF);
}

function	sendIdPlayer(sock) {
    sock.write("1:0;9:id_player;6:player;0:;0:;1:0" + CRLF);
}

function	sendAllPlayer(sock, players, ia) {
    var data = ""
    for (var i = 0; i < players.length; i++) {
	data += players[i].serialize() + "|";
    }
    data += ia.serialize() + "|";
    sock.write("1:0;10:all_player;6:player;0:;0:;" + data.length + ":" + data + CRLF);
}

function	sendUpdateMap(sock, map) {
    for (var i = 0; i < map.objects.length; i++) {
	var sr = map.objects[i].serialize();
	var tr = "1:0;4:tile;6:player;0:;0:;" + (sr + '').length + ":" + sr + CRLF;
	sock.write(tr);
    }
    for (var i = 0; i < map.players.length; i++) {
	var sr = map.players[i].serialize();
	var tr = "1:0;6:player;6:player;0:;0:;" + (sr + '').length + ":" + sr + CRLF;
	sock.write(tr);
    }
    sendNextStep(sock);
}

function	sendNextStep(sock) {
    setTimeout(function () {
	    sock.write("1:0;8:nextstep:6:player;0:;0:;0:" + CRLF);
	}, 100);
}

exports.sendMap = sendMap;
exports.sendIdNetwork = sendIdNetwork;
exports.sendIdPlayer = sendIdPlayer;
exports.sendAllPlayer = sendAllPlayer;
exports.sendUpdateMap = sendUpdateMap;
exports.sendNextStep = sendNextStep;
