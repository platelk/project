
/////////////////////////////
// GLOBAL VARIABLE
/////////////////////////////

var tools = {};
tools["addObject"] = addObject;
tools["addCollider"] = addCollider;
tools["selectObject"] = selectObject;
tools["addPlayer"] = addPlayer;
tools["movePlayer"] = movePlayer;
tools["throwBomb"] = throwBomb;

/////////////////////////////
// RENDER
/////////////////////////////

function	Render() {
    this.map = new Map();
    this.canvas = document.getElementById("map");
    this.context = this.canvas.getContext("2d");
    this.view = "full";
    this.tool = "addObject";
    this.objectSelected = null;
    this.dragable = false;
    this.canDrag = false;
    this.cursor = null;
    this.toolConf = null;
    this.explose = false;
    this.gameEnd = false;
}

/////////////////////////////
// CURSOR
/////////////////////////////

function	Cursor(type, size) {
    this.x = 0;
    this.y = 0;
    this.type = type;
    this.size = size;
}

Cursor.prototype.draw = function (render) {
    render.map.draw(render, render.view);
    render.context.fillStyle = cursor_color;
    render.context.beginPath();
    render.context.arc(this.y, this.x, this.size, 0, complete_circle);
    render.context.fill();
}

/////////////////////////////
// VIEW
/////////////////////////////

function	changeView(render, state) {
    if (state == "full" || state == "collider" || state == "object" || state == "move_player" || state == "throw_bomb")
	render.view = state;
}

////////////////////////////
// MOUSE
////////////////////////////

function getPosition(e) {
    var targ;
    if (!e)
        e = window.event;
    if (e.target)
        targ = e.target;
    else if (e.srcElement)
        targ = e.srcElement;
    var x = e.pageX - $(targ).offset().left;
    var y = e.pageY - $(targ).offset().top;
    return {"x": x, "y": y};
};

/////////////////////////////
// TOOLS
/////////////////////////////

function	addObject(render, x, y) {
    var obj = render.map.addObject(x, y, render.toolConf.type);
    render.map.draw(render, render.view);
    return (obj);
}

function	selectObject(render, x, y) {
    render.objectSelected = render.map.getObjectWithPos(x, y);
    render.map.draw(render, render.view);
}

function	addCollider(render, x, y) {
    if (render.objectSelected !== null) {
	render.map.addObjectCollider(render.objectSelected, x, y, render.toolConf.value);
	render.map.draw(render, render.view);
    }
}

function	addPlayer(render, x, y) {
    render.map.addPlayer(x, y, 25, 10, 100);
    render.map.draw(render, render.view);
}
function	movePlayer(render, x, y) {
    var pl = render.map.getPlayerWithPosSpeed(x, y);
    console.log(pl);
    if (pl !== null && pl.moved == false) {
	console.log("move ok");
	pl.x = x;
	pl.y = y;
	pl.moved = true;
    }
    render.map.draw(render, render.view);
}

function	throwBomb(render, x, y) {
    var pl = render.map.getPlayerWithPosBomb(x, y, render.toolConf.radius);
    console.log(pl);
    if (pl !== null && pl.throwbomb == false) {	
	render.map.addBomb(x, y, render.toolConf.radius, render.toolConf.timeout);
	pl.throwbomb = true;
    }
    render.map.draw(render, render.view);
}

////////////////////////////
// NEXT STEP
////////////////////////////

function	nextStep(render, socket) {
    socket.emit('update', render.map);
    for (var i = 0; i < render.map.players.length; i++) {
	render.map.players[i].moved = false;
	render.map.players[i].throwbomb = false;
    }    
}

////////////////////////////
// TOOLS CONFIG
////////////////////////////

function	ConfCollider() {
    return ('<label>Size: <span id="colliderRangeValue">0</span></label><input type="range" id="colliderRange" name="points" min="1" max="200" />');    
}

function	ControllerCollider(render) {
    render.cursor = new Cursor("circle", 20);
    var p = document.getElementById("colliderRange")
    p.addEventListener("input", function() {
	render.toolConf = {'value': p.value};
	render.cursor = new Cursor("circle", p.value);
	$("#colliderRangeValue").html(p.value);
    }, false);
}

function	ConfObject(render) {
    return ('<label>Type: </label><input type="number" id="objectType" name="quantity" min="1" max="5">');
}

function	ControllerObject(render) {
    render.toolConf = {'type': 0};
    var p = document.getElementById("objectType");
    p.addEventListener("input", function() {
	render.toolConf = {'type': p.value};
    }, false);
}

function	ConfBomb(render) {
    return ('<label>Radius : <span id=bombRadiusValue>5</span></label><input type="range" id="bombRadius" name="points" min="1" max="50" /><label>Timeout: </label><input type="number" id="bombTimeout" name="timeout" min="1" max="50" />');
}

function	ControllerBomb(render) {
    render.toolConf = {'radius': 20, 'timeout': 5};
    var p = document.getElementById("bombTimeout");
    p.addEventListener("input", function() {
	render.toolConf.timeout = p.value;
	$("#bombTimeoutValue").html(p.value);
    }, false);
    var t = document.getElementById("bombRadius");
    t.addEventListener("input", function() {
	render.toolConf.radius = t.value;
	$("#bombRadiusValue").html(t.value);
    }, false);
}
