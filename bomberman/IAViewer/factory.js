
/////////////////////////////
// MODULE REQUIRE
/////////////////////////////

var buffRead = require("buffered-reader");
var xml_parser = require('libxml-to-js');
var bomberman_parser = require('./parser.js');

/////////////////////////////
// UTILS
/////////////////////////////

function	UCircle(x, y, radius) {
    this.radius = radius;
    this.x = x;
    this.y = y;
}

var components = {};
components.life = CLife;
components.colider = CCollider;
components.position = CPosition;
components.move = CMove;
components.explose = CExplose;
components.throw_bomb = CThrowBomb;

var objects = {};
objects.player = OPlayer;
objects.decor = ODecor;

/////////////////////////////
// COMPONENTS
/////////////////////////////

function	CLife(life) {
    if (life.length != 1)
	throw new Error("[Component]: life missing argument");
    this.life = parseInt(life[0], 10);
    return (this);
}

function	CCollider(collider) {
    this.bounding = [];
    for (var i = 0; i < collider.length; i += 4)
	if (i + 4 >= collider.length) {
	    this.bounding.push(new UCircle(parseInt(collider[i], 10), parseInt(collider[i + 1], 10), parseInt(collider[i + 2], 10), parseInt(collider[i + 3], 10)));
	}
}

function	CPosition(position) {
    if (position.length != 6)
	throw new Error("[Component]: position missing argument");
    this.px = parseInt(position[0], 10);
    this.py = parseInt(position[1], 10);
    this.pz = parseInt(position[2], 10);
    this.dx = parseFloat(position[3]);
    this.dy = parseFloat(position[4]);
    this.dz = parseFloat(position[5]);
}

function	CMove(move) {
    if (move.length !== 0)
	throw new Error("[Component]: move missing argument");
}

function	CExplose(explose) {
    if (explose.length != 3)
	throw new Error("[Component]: explose missing argument");
    this.timeout = explose[0];
    this.strength = explose[1];
    this.effect = explose[2];
}

function	CThrowBomb(throwbomb) {
    if (throwbomb.length != 1)
	throw new Error("[Component]: throwbomb missing argument");
    this.recovery = throwbomb[0];
}

/////////////////////////////
// OBJECTS
/////////////////////////////

function	ODecor(decor) {
    this.name = decor[0];
    this.id = decor[1];
    this.components = buildComponents(decor[2]);
}

function	OPlayer(decor) {
    this.name = decor[0];
    this.id = decor[1];
    this.components = buildComponents(decor[2]);
}

/////////////////////////////
// FACTORY
/////////////////////////////

function	buildComponents(comp) {
    var name, obj, li_comp = [];
    for (var i = 0; i < comp.length; i++) {
	name = comp[i][0];
	obj = components[name];
	if (obj !== undefined) {
	    try {
		li_comp.push({"name": name, "object": new obj(comp[i][1])});
	    }
	    catch (e) {
		throw new Error("[Component]: missing argument: " + e);
	    }
	}
    }
    return (li_comp);
}

function	buildObjects(obj) {
    var name, id, res, li_obj = [];
    for (var i = 0; i < obj.length; i++) {
	name = obj[i][0];
	res = objects[name];
	if (res !== undefined) {
	    try {   
		li_obj.push({"name": name, "object": new res(obj[i])});
	    }
	    catch (e) {
		throw new Error("[GameObject]: missing argument: " + e);
	    }
	}
    }
    return (li_obj);
}

function	relMapToSimpleMap(rel, map) {
    for (var i = 0; i < rel.length; i++) {
	var collider = null;
	var position = null;

	for (var j = 0; j < rel[i].object.components.length; j++) {
	    if (rel[i].object.components[j].name == "colider") {
		collider = rel[i].object.components[j].object.bounding;
	    }
	    else if (rel[i].object.components[j].name == "position") {
		position = rel[i].object.components[j].object;
	    }
	}
	if (collider != null && position != null)
	    map.addObject(null, position.px, position.py, collider);
    }
}

function	buildMap(file, map) {
    var contents = "";
    var map;
    var reader = new buffRead.DataReader(file, {encoding: "utf8"});
    reader.on("error", function (error) {
	throw new Error("file not found");
    });
    reader.on("line", function (line) {
	contents += line;
    });
    reader.on("end", function () {
	xml_parser(contents, '//Map/Content', function (error, result) {
	    if (error) {
		console.error(error);
		throw new Error("not a valid xml file");
	    }
	    else {
		var parsed = bomberman_parser.parse(result[0]['@'].serial);
		var rel_map = buildObjects(parsed);
		relMapToSimpleMap(rel_map, map);
	    }
	});
    });
    reader.read();
}


/////////////////////////////
// MODULE EXPORT
/////////////////////////////

exports.buildComponents = buildComponents;
exports.buildObjects = buildObjects;
exports.buildMap = buildMap;
