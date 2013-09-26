
/////////////////////////////
// MODULE REQUIRE
/////////////////////////////

var fs = require("fs");
var url = require("url");
var path = require('path');
var parse = require('./parser.js');

/////////////////////////////
// ROUTES
/////////////////////////////

var	handle = {};
var	handleTCP = {};
handle['/']			= ["client/index.html", "text/html"];
handle['/favicon.ico']		= ["client/favicon.ico", "image/x-icon"];
handle['/img/icones.png']	= ["client/bootstrap/img/icones.png", "image/png"];
handle['/img/icones-white.png']	= ["client/bootstrap/img/icone-white.png", "image/png"];
handle['/img/grass.png']	= ["client/img/grass.jpg", "image/jpeg"];
handle['/css/style.css']	= ["client/css/style.css", "text/css"];
handle['/css/bootstrap.min.css'] = ["client/bootstrap/css/bootstrap.min.css", "text/css"];
handle['/js/index.js']		= ["client/js/index.js", "application/javascript"];
handle['/js/map.js']		= ["client/js/map.js", "application/javascript"];
handle['/js/render.js']		= ["client/js/render.js", "application/javascript"];
handle['/js/bootstrap.min.js']	= ["client/bootstrap/js/bootstrap.min.js", "application/javascript"];

handleTCP['move'] = RequestMove;
handleTCP['throw_bomb'] = RequestThrowBomb;
handleTCP['endstep'] = RequestEndStep;
handleTCP['log'] = RequestLog;

/////////////////////////////
// UTILS FUNCTIONS
/////////////////////////////

function	sendFile(res, file, mime) {
    var file_path = path.join(__dirname, "/", file);
    var stat = fs.statSync(file_path);

    res.writeHead(200, {
        'Content-Type': mime,
        'Content-Length': stat.size
    });

    var read_stream = fs.createReadStream(file_path);
    read_stream.pipe(res);
}

function	send(res, data) {
    sendFile(res, data[0], data[1]);
}

/////////////////////////////
// TCP REQUEST
/////////////////////////////

function	RequestMove(tab, map, io_sock) {
    var r = tab[5].split("|");
    map.ia.x += parseInt(r[0], 10);
    map.ia.y += parseInt(r[1], 10);
}

function	RequestThrowBomb(tab, map, io_sock) {
    var r = tab[5].split("|");
    var dir = {'x': map.ia.x + parseInt(r[0], 10), 'y': map.ia.y + parseInt(r[1], 10)};
    var strength = r[3];
    map.addBomb(null, dir.x, dir.y, strength, 5);
    if (io_sock !== undefined && io_sock !== null) {
	ioBuffer.push(['map', JSON.stringify(map)]);
    }
}

function	RequestEndStep(tab, map, io_sock) {
    if (io_sock !== undefined && io_sock !== null) {
	ioBuffer.push(['map', JSON.stringify(map)]);
	ioBuffer.push(['endstep', 'ok']);
    }
}

function	RequestLog(tab, map, io_sock) {
    if (io_sock !== undefined && io_sock !== null && tab.length == 6) {
	ioBuffer.push(['log', tab[5]]);
    }
}

/////////////////////////////
// ROUTER
/////////////////////////////

function	route(req, res) {
    try {
	send(res, handle[url.parse(req.url).pathname]);
    }
    catch (e) {
	res.writeHead(404, {'Content-Type': 'text/plain'});
	res.end("404 Not found (" + e + ")");
    }
}

function	updateTCPActions() {
    for (var i = 0; i < ioInput.length; i++) {
	try {
	    var tr = ioInput[i].split("\r\n");
	    for (var j = 0; j < tr.length; j++) {
		if (tr[j] !== "") {
		    var res = parse.parseTCP(tr[j]);
		    if (res !== null) {
			handleTCP[res[1]](res, current_map, io_sock);
		    }
		}
	    }
	}
	catch (e) {
	    console.log("[Error]: unknow or bad cmd [" + ioInput[i] + "]");
	}
	ioInput.splice(i, 1);
    }
}

function	initActions (map, io_sock) {
    updateTCPActions.map = map;
    updateTCPActions.io_sock = io_sock;
    setInterval(updateTCPActions, 100);
}

/////////////////////////////
// MODULE EXPORT
/////////////////////////////

exports.route = route;
exports.initActions = initActions;
