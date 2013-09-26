
/////////////////////////////
// MODULE REQUIRE
/////////////////////////////

var net = require("net");
var route = require("./router.js");
var http = require("http");
var io = require("socket.io");
var sockio = require("./sockio.js");
var tcp = require("./tcp.js");
var map = require("./map.js");

/////////////////////////////
// GLOBAL VARIABLES
/////////////////////////////

var tcp_sock = null;
io_sock = null;
var HOST = '127.0.0.1';
var TCP_PORT = 6969;
var HTTP_PORT = 80;
current_map = map.Map();
current_map.load("./map_1.xml");
ioBuffer = [];
ioInput = [];

/////////////////////////////
// SERVER
/////////////////////////////

function	connectIA(sock) {
    tcp.sendIdNetwork(sock);
    tcp.sendIdPlayer(sock);
    tcp.sendMap(sock, current_map.objects);
    tcp.sendAllPlayer(sock, current_map.players, current_map.ia);
}

function	start() {
    var client_id = 0;

    function	onHttpRequest(req, res) {
	route.route(req, res);
    }
    function	onTcpRequest(sock) {
	sock.setEncoding("utf-8");
	console.log("connected: " + client_id);
	connectIA(sock);
	sock.addListener('data', function(data) {
	    ioInput.push(data);
	});
	tcp_sock = sock;
	client_id++;
    }
    function	onConnected(sock) {
	current_map.sendMap(sock, current_map);
	sock.on('update', function (data) {
	    sockio.update(current_map, data);
	    for (var i = 0; i < current_map.bombs.length; i++) {
		current_map.bombs[i].update(current_map, sock);
	    }
	    tcp.sendUpdateMap(tcp_sock, current_map);
	});
	io_sock = sock;
	route.initActions(current_map, io_sock);
    }
    
    var serverHttp = http.createServer(onHttpRequest).listen(HTTP_PORT);
    var serverWs = io.listen(serverHttp);
    var serverUdp = net.createServer(onTcpRequest).listen(TCP_PORT, HOST);
    serverWs.sockets.on("connection", onConnected);
    serverWs.set('log level', 0);
    setInterval(function () {
	for (var i = 0; i < ioBuffer.length; i++) {
	    io_sock.emit(ioBuffer[i][0], ioBuffer[i][1]);
	}
	ioBuffer = [];
    }, 10);
}

/////////////////////////////
// MODULE EXPORT
/////////////////////////////

exports.start = start;
