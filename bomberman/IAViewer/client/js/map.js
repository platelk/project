

////////////////////////////
// GLOBAL VARIABLE
/////////////////////////////

var complete_circle = 2 * Math.PI;
var life_color = "rgba(255, 10, 10, 0)";
var object_color = "rgba(107, 96, 46, 0.8)";
var collider_color = "rgba(111, 181, 76, 0.4)";
var selected_color = "rgba(255, 20, 20, 0.7)";
var player_color = "rgba(20, 20, 250, 0.4)";
var explose_color = "rgba(255, 20, 20, 0.7)";
var ia_color = "rgba(250, 150, 10, 0.4)";
var player_move_color = "rgba(20, 20, 250, 0.1)";
var player_throw_color = "rgba(255, 160, 10, 0.2)";
var dot_color = "rgba(0, 0, 0, 1)";
var cursor_color = "rgba(0, 0, 0, 0.1)";
var text_color = "rgba(0, 0, 0, 1)";
var object_circle = 20;
var player_circle = 2;
var player_throw_range = 40;

/////////////////////////////
// UTILS
/////////////////////////////

function clearCanvas(context, canvas) {
    context.clearRect(0, 0, canvas.width, canvas.height);
    var w = canvas.width;
    canvas.width = 1;
    canvas.width = w;
}

/////////////////////////////
// GAME OBJECT
/////////////////////////////

function	UCircle(x, y, radius) {
    this.radius = radius;
    this.x = x;
    this.y = y;
}

function	GameObject(id, x, y, collider, type) {
    this.id = id;
    this.x = x;
    this.y = y;
    if (type === undefined)
	this.type = 0;
    else
	this.type = type;
    this.collider = collider;
}

GameObject.prototype.drawCollider = function (context, offsetx, offsety) {
    if (this.collider !== null) {
	for (var i = 0; i < this.collider.length; i++) {
	    var posx = (this.collider[i].x + this.x) - offsetx;
	    var posy = (this.collider[i].y + this.y) - offsety;
	    context.fillStyle = collider_color;
	    context.beginPath();
	    context.arc(posx, posy, this.collider[i].radius, 0, complete_circle);
	    context.stroke();
	    context.fill();
	}
    }
};

GameObject.prototype.drawObject = function (context, offsetx, offsety, color) {
    var posx = this.x - offsetx;
    var posy = this.y - offsety;
    context.fillStyle = color;
    context.beginPath();
    context.arc(posx, posy, object_circle, 0, complete_circle);
    context.stroke();
    context.fill();
    context.fillStyle = text_color;
    context.font="12px Georgia";
    context.fillText(this.type, posx, posy);
};

GameObject.prototype.move = function (x, y) {
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
    }    return (0);
};

/////////////////////////////
// PLAYER
/////////////////////////////

function	Player(id, x, y, speed, size, life) {
    this.id = id;
    this.x = x;
    this.y = y;
    this.speed = speed;
    this.size = size;
    this.life = life;
    this.moved = false;
    this.throwbomb = false;
}

Player.prototype.move = function (render, x, y) {
    if (this.collide(render, x, y) == false) {
	this.x = x;
	this.y = y;
    }
};

Player.prototype.collide = function (render, x, y) {
    for (var i = 0; i < render.map.objects.length; i++) {
	var obj = render.map.objects[i];
	for (var j = 0; j < obj.collider.length; j++) {
	    var d = MATH.pow(MATH.pow(x - obj.collider[i].x, 2) + MATH.pow(y - obj.collider[i].y, 2), 0.5);
	    if (d <= this.size + obj.collider[i].radius)
		return true;
	}
    }
    return false;
};

Player.prototype.drawLife = function (context, offsetx, offsety) {
    var posx = this.x - offsetx;
    var posy = this.y - offsety;
    context.beginPath();
    var angle = (complete_circle / 100) * this.life;
    context.arc(posx, posy, this.size + 5, 0, angle);
    context.lineWidth = 5;
    context.strokeStyle = '#FF2222';
    context.stroke();
    context.lineWidth = 1;
    context.strokeStyle = '#000000';

}

Player.prototype.draw = function (context, offsetx, offsety, color, type) {
    var posx = this.x - offsetx;
    var posy = this.y - offsety;
    if (type == "move_player" && this.moved == false) {
	context.fillStyle = player_move_color;
	context.beginPath();
	context.arc(posx, posy, this.speed, 0, complete_circle);
	context.stroke();
	context.fill();
	context.fillStyle = color;
	context.beginPath();
	context.arc(posx, posy, this.size, 0, complete_circle);
	context.stroke();
	context.fill();
    }
    else if (type == "throw_bomb" && this.throwbomb == false) {
	context.fillStyle = player_throw_color;
	context.beginPath();
	context.arc(posx, posy, player_throw_range, 0, complete_circle);
	context.stroke();
	context.fill();
	context.fillStyle = color;
	context.beginPath();
	context.arc(posx, posy, this.size, 0, complete_circle);
	context.stroke();
	context.fill();
    }
    else {
	context.fillStyle = color;
	context.beginPath();
	context.arc(posx, posy, this.size, 0, complete_circle);
	context.stroke();
	context.fill();
    }
    this.drawLife(context, offsetx, offsety);
};

////////////////////////////
// BOMBS
////////////////////////////

function	Bomb(id, x, y, radius, timeout) {
    this.id = id;
    this.x = x;
    this.y = y;
    this.radius = radius;
    this.timeout = timeout;
}

Bomb.prototype.prepare_explose = function (render) {
    var posx = this.x - render.map.offsetx;
    var posy = this.y - render.map.offsety;
    render.context.fillStyle = explose_color;
    render.context.beginPath();
    render.context.arc(posx, posy, this.radius, 0, complete_circle);
    render.context.stroke();
    render.context.fill();
}

Bomb.prototype.draw = function (context, offsetx, offsety) {
    var posx = this.x - offsetx;
    var posy = this.y - offsety;
    context.fillStyle = player_throw_color;
    context.beginPath();
    context.arc(posx, posy, this.radius, 0, complete_circle);
    context.stroke();
    context.fill();
    context.fillStyle = text_color;
    context.font="12px Georgia";
    context.fillText(this.timeout, posx, posy);
}

/////////////////////////////
// MAP
/////////////////////////////

function	Map() {
    this.objects = [];
    this.players = [];
    this.bombs = [];
    this.offsetx = 0;
    this.offsety = 0;
    this.ia = null;
}

Map.prototype.move = function (x, y) {
    this.offsetx = x;
    this.offsety = y;
};

Map.prototype.draw = function (render, what) {
    if (render.gameEnd === true)
	return;
    clearCanvas(render.context, render.canvas);
    for (var i = 0; i < this.objects.length; i++) {
	if (this.objects[i] != render.objectSelected)
	    this.objects[i].drawObject(render.context, this.offsetx, this.offsety, object_color);
	else
	    this.objects[i].drawObject(render.context, this.offsetx, this.offsety, selected_color);
	this.objects[i].drawCollider(render.context, this.offsetx, this.offsety, collider_color);
	
    }
    for (var i = 0; i < this.players.length; i++)
	this.players[i].draw(render.context, this.offsetx, this.offsety, player_color, what);
    for (var i = 0; i < this.bombs.length; i++)
	this.bombs[i].draw(render.context, this.offsetx, this.offsety);
    this.ia.draw(render.context, this.offsetx, this.offsety, ia_color);
};

Map.prototype.getObjectWithPos = function (x, y) {
    for (var i = 0; i < this.objects.length; i++) {
	var d = (x -this.objects[i].x) * (x - this.objects[i].x) + (y - this.objects[i].y) * (y - this.objects[i].y);
	if (d <= object_circle * object_circle)
	    return (this.objects[i]);
    }
    return (null);
};

Map.prototype.getPlayerWithPosSpeed = function (x, y) {
    for (var i = 0; i < this.players.length; i++) {
	var d = (x -this.players[i].x) * (x - this.players[i].x) + (y - this.players[i].y) * (y - this.players[i].y);
	console.log("spd = " + this.speed + " d = " + d + " rad = " + this.speed * this.speed);
	if (d <= this.players[i].speed * this.players[i].speed)
	    return (this.players[i]);
    }
    return (null);
};
Map.prototype.getPlayerWithPosBomb = function (x, y, radius) {
    for (var i = 0; i < this.players.length; i++) {
	var d = (x -this.players[i].x) * (x - this.players[i].x) + (y - this.players[i].y) * (y - this.players[i].y);
	console.log("spd = " + this.speed + " d = " + d + " rad = " + this.speed * this.speed);
	if (d <= player_throw_range * player_throw_range)
	    return (this.players[i]);
    }
    return (null);
};

Map.prototype.addObject = function (x, y, type) {
    var obj = new GameObject(null, x, y, [], type);
    this.objects.push(obj);
    return (obj);
};

Map.prototype.addObjectCollider = function (obj, x, y, radius) {
    for (var i = 0; i < this.objects.length; i++) {
	if (this.objects[i] == obj) {
	    var posx = x - obj.x;
	    var posy = y - obj.y;
	    this.objects[i].collider.push(new UCircle(posx, posy, radius));
	    return;
	}
    }
};

Map.prototype.addBomb = function (x, y, radius, timeout) {
    var bmb = new Bomb(null, x, y, radius, timeout);
    this.bombs.push(bmb);
    return (bmb);
}

Map.prototype.addPlayer = function (x, y, speed, radius, life) {
    var pl = new Player(null, x, y, speed, radius, life);
    this.players.push(pl);
    return (pl);
}

Map.prototype.getObject = function (obj) {
    for (var i = 0; i < this.objects.length; i++) {
	if (this.objects[i] == obj)
	    return (this.objects[i]);
    }
    return (null);
};

Map.prototype.getPlayer = function (pl) {
    for (var i = 0; i < this.players.length; i++) {
	if (this.players[i] == pl)
	    return (this.players[i]);
    }
    return (null);
};

Map.prototype.getBomb = function (id) {
    for (var i = 0; i < this.bombs.length; i++) {
	console.log("bombs = " + this.bombs[i].id + " id = " + id);
	if (this.bombs[i].id == id)
	    return (this.bombs[i]);
    }
    return (null);
};

Map.prototype.update = function (render, serialized) {
    var unserialized = JSON.parse(serialized);
    this.objects = [];
    this.players = [];
    this.bombs = [];
    this.ia = new Player(0, unserialized.ia.x, unserialized.ia.y, unserialized.ia.speed, unserialized.ia.radius, unserialized.ia.life);
    for (i = 0; i < unserialized.objects.length; i++) {
	var obj = unserialized.objects[i];
	this.objects.push(new GameObject(obj.id, obj.x, obj.y, obj.collider));
    }
    for (i = 0; i < unserialized.players.length; i++) {
	var obj = unserialized.players[i];
	this.players.push(new Player(obj.id, obj.x, obj.y, obj.speed, obj.radius, obj.life));
    }
    for (i = 0; i < unserialized.bombs.length; i++) {
	var obj = unserialized.bombs[i];
	this.bombs.push(new Bomb(obj.id, obj.x, obj.y, obj.radius, obj.timeout));
    }
    this.draw(render, render.view);
};
