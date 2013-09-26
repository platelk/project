
var factory = require("./factory.js");

/////////////////////////////
// UTILS
/////////////////////////////

function	collideCircleCircle(x1, y1, x2, y2, r1, r2) {
    var d = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
    if (d < parseInt(r1, 10) + parseInt(r2, 10))
	return true;
    return false;
}

/////////////////////////////
// GAME OBJECT
/////////////////////////////

var ia_id = 0;
var object_id = 1;

function	GameObject(id, x, y, collider) {
    if (id === null) {
	this.id = object_id;
	object_id++;
    }
    else
	this.id = id;
    this.x = x;
    this.y = y;
    this.collider = collider;
}

GameObject.prototype.setPos = function (x, y) {
    this.x = x;
    this.y = y;
};

GameObject.prototype.collide = function (x, y) {
    for (var i = 0; i < this.collider.length; i++) {
	var rel_cord = {'x': this.x + this.collider[i].x, 'y': this.y + this.collider[i].y};
	r = (rel_cord.x - x) * (rel_cord.x - x) + (rel_cord.y - y) * (rel_cord.y - y);
	if (r < this.collider[i].radius) {
	    return (1);
	}
    }
    return (0);
};

GameObject.prototype.serialize = function () {
    var collider_args = "";
    for (var i = 0; i < this.collider.length; i++) {
	if (i !== 0)
	    collider_args += ";";
	collider_args += "i:" + (this.collider[i].x + '').length + ":" + this.collider[i].x + ";";
	collider_args += "i:" + (this.collider[i].y + '').length + ":" + this.collider[i].y + ";";
	collider_args += "i:1:0;";
	collider_args += "i:" + (this.collider[i].radius + '').length + ":" + this.collider[i].radius;
    }
    var collider = "CP:7:colider:" + (collider_args.length + 2) + ":{" + collider_args + "}";
    var position_args = "i:" + (this.x + '').length + ":" + this.x + ";i:" + (this.y + '').length + ":" + this.y + ";i:1:0;d:1:0;d:1:0;d:1:0";
    var position = "CP:8:position:" + (position_args.length + 2) + ":{" + position_args + "}";
    var component = collider + ";" + position;
    var data = "GO:5:decor:" + (this.id + '').length + ":" + this.id + ":" + (component.length + 2) + ":{" + component + "}";
    return (data);
};


/////////////////////////////
// BOMBS
/////////////////////////////

function	Bomb(id, x, y, radius, timeout) {
    if (id === null) {
	this.id = object_id;
	object_id++;
    }
    else
	this.id = id;
    this.timeout = timeout;
    this.x = x;
    this.y = y;
    this.radius = radius;
    this.explosed = false;
}

Bomb.prototype.explose = function (map, sock) {
    ioBuffer.push(['explose', this]);
    //sock.emit('explose', this);
    for (var i = 0; i < map.objects.length; i++) {	
	for (var j = 0; j < map.objects[i].collider.length; j++) {
	    var obj = map.objects[i].collider[j];
	    var pos = {'x': obj.x + map.objects[i].x, 'y': obj.y + map.objects[i].y};
	    if (collideCircleCircle(this.x, this.y, pos.x, pos.y, this.radius, obj.radius) === true) {
		map.objects.splice(i, 1);
		break;
	    }
	}
    }
    for (var i = 0; i < map.players.length; i++) {
	var pl = map.players[i];
	var ppos = {'x': pl.x, 'y': pl.y};
	if (collideCircleCircle(this.x, this.y, ppos.x, ppos.y, this.radius, pl.radius) === true) {
	    pl.life -= 50;
	    if (pl.life <= 0)
		map.players.splice(i, 1);
	}	
    }
    if (collideCircleCircle(this.x, this.y, map.ia.x, map.ia.y, this.radius, map.ia.radius) === true) {
	map.ia.life -= 50;
	if (map.ia.life <= 0) {
	    map.ia.life = 0;
	    ioBuffer.push(['EndOfGame', 'ia die']);
	    //sock.emit('EndOfGame', 'ia die');
	}
    }
	
    for (var i = 0; i < map.bombs.length; i++) {
	var bmb = map.bombs[i];
	if (bmb.explosed != true && bmb.id != this.id && collideCircleCircle(this.x, this.y, bmb.x, bmb.y, this.radius, bmb.radius))
	{
	    bmb.explosed = true;
	    bmb.explose(map, sock);
	}
    }
    var i = map.bombs.indexOf(this);
    map.bombs.splice(i, 1);
}

Bomb.prototype.update = function (map, sock) {
    this.timeout--;
    if (this.timeout <= 0)
	this.explose(map, sock);
}

/////////////////////////////
// PLAYER
/////////////////////////////

function	Player(id, x, y, radius, speed, life) {
    if (id === null) {
	this.id = object_id;
	object_id++;
    }
    else
	this.id = id;
    this.x = x;
    this.y = y;
    this.life = life;
    this.radius = radius;
    this.speed = speed;
}

Player.prototype.move = function (direction) {
    var new_dir = [this.speed * Math.cos(direction), this.speed * Math.sin(direction)];
    this.x = this.x + new_dir[0];
    this.y = this.y + new_dir[1];
};

Player.prototype.serialize = function () {
    var collider_args = "i:1:0;i:1:0;i:1:0;i:" + (this.radius + '').length + ":" + this.radius;
    var collider = "CP:7:colider:" + (collider_args.length + 2) + ":{" + collider_args + "}";
    var position_args = "i:" + (this.x + '').length + ":" + this.x + ";i:" + (this.y + '').length +	":" + this.y + ";i:1:0;d:1:0;d:1:0;d:1:0";
    var position = "CP:8:position:" + (position_args.length + 2) + ":{" + position_args + "}";
    var life_args = "i:3:100";
    var life = "CP:4:life:" + (life_args.length + 2) + ":{" + life_args + "}";
    var component = collider + ";" + position + ";" + life;
    var data = "GO:6:player:" + (this.id + '').length + ":" + this.id + ":" + (component.length + 2) + ":{" + component + "}";
    return (data);
};

/////////////////////////////
// MAP
/////////////////////////////

function	Map() {
    this.objects = [];
    this.bombs = [];
    this.players = [];
    this.ia = new Player(0, 300, 300, 30, 30, 100);
}

Map.prototype.load = function (file) {
    factory.buildMap(file, this);
}

Map.prototype.addObject = function (id, x, y, collider) {
    var obj = new GameObject(id, x, y, collider);
    this.objects.push(obj);
    return (obj);
};

Map.prototype.addPlayer = function (id, x, y, radius, speed, life) {
    var obj = new Player(id, x, y, radius, speed, life);
    this.players.push(obj);
    return (obj);
};

Map.prototype.addBomb = function (id, x, y, radius, timeout) {
    var bmb = new Bomb(id, x, y, radius, timeout);
    this.bombs.push(bmb);
    return (bmb);
};

Map.prototype.removeObject = function (x, y) {
    for (var i = 0; i < this.objects.length; i++)
	if (this.objects[i].collide(x, y) == 1)
	    this.objects.splice(i, 1);
};

Map.prototype.addCollider = function (collider) {
    return (["bounding", collider]);
};

Map.prototype.updateObject = function (obj) {
    for (var i = 0; i < this.objects.length; i++) {
	if (obj.id == this.objects[i].id) {
	    this.objects[i].x = obj.x;
	    this.objects[i].y = obj.y;
	    this.objects[i].collider = obj.collider;
	    return;
	}
    }
    var x = this.addObject(null, obj.x, obj.y, obj.collider);
}
Map.prototype.updatePlayer = function (obj) {
    for (var i = 0; i < this.players.length; i++) {
	if (obj.id == this.players[i].id) {
	    this.players[i].x = obj.x;
	    this.players[i].y = obj.y;
	    this.players[i].speed = obj.speed;
	    this.players[i].radius = obj.size;
	    this.players[i].life = obj.life;
	    return;
	}
    }
    var x = this.addPlayer(null, obj.x, obj.y, obj.size, obj.speed, obj.life);
}

Map.prototype.sendMap = function (sock, map) {
    ioBuffer.push(['map', JSON.stringify(this)]);
    //sock.emit("map", JSON.stringify(this));
};

Map.prototype.updateBomb = function (obj) {
    for (var i = 0; i < this.bombs.length; i++) {
	if (obj.id == this.bombs[i].id) {
	    this.bombs[i].x = obj.x;
	    this.bombs[i].y = obj.y;
	    this.bombs[i].radius = obj.radius;
	    this.bombs[i].timeout = obj.timeout;
	    return;
	}
    }
    var x = this.addBomb(null, obj.x, obj.y, obj.radius, obj.timeout);
}

function	createMap() {
    return (new Map());
}
function	createGameObject(x, y, collider) {
    return (new GameObject(null, x, y, collider));
}
function	createPlayer(x, y, radius, speed, life) {
    return (new Player(null, x, y, radius, speed, life));
}


/////////////////////////////
// MODULE EXPORT
/////////////////////////////

exports.Map = createMap;
exports.GameObject = createGameObject;
exports.Player = createPlayer;

