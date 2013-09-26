
function init() {
    var render = new Render();
    var socket = io.connect();
    init_event(render, socket);
    socket.on("map", function (data) {
//	data = data;
	console.log(data);
	if (render.explose == true) {
	    setTimeout(function () {
		render.map.update(render, data);
	    }, 10);
	}
	else
	    render.map.update(render, data);
	render.explose = false;
    });
    socket.on("endstep", function (data) {
	$("#nextStep").removeAttr('disabled');
    });
    socket.on("explose", function (data) {
	var bmb = render.map.getBomb(data['id']);
	bmb.prepare_explose(render);
	render.explose = true;
    });
    socket.on("EndOfGame", function (data) {
	console.log("receive end og game");
	render.context.beginPath();
	render.context.rect(0, 0, 800, 500);
	render.context.fillStyle = '#404040';
	render.context.fill();
	render.context.fillStyle = '#ffffff';
	render.context.font ="20px Georgia";
	render.context.fillText("Your IA is Dead, Please Fix it!", 200, 250);
	render.gameEnd = true;
    });
    render.socket = socket;
    return (render);
}

function	init_event(render, socket) {
    render.canvas.addEventListener("mousedown", function (e) {
	if (render.gameEnd == false) {
	    if (render.canDrag == true) {
		render.dragable = true;
		var x = e.layerX - render.canvas.offsetLeft;
		var y = e.layerY - render.canvas.offsetTop;
		render.objectSelected = render.map.getObjectWithPos(x, y);
	    }
	}
    });
    render.canvas.addEventListener("mouseup", function (e) {
	if (render.gameEnd == false) {
	    if (render.canDrag == true) {
		render.dragable = false;
		var x = e.layerX - render.canvas.offsetLeft;
		var y = e.layerY - render.canvas.offsetTop;
	    }
	}
    });
    render.canvas.addEventListener("mousemove", function (e) {
	if (render.gameEnd == false) {
	    if (render.dragable == true) {
		if (render.objectSelected !== null) {
		    var x = e.layerX - render.canvas.offsetLeft;
		    var y = e.layerY - render.canvas.offsetTop;
		    render.objectSelected.x = x;
		    render.objectSelected.y = y;
		    render.map.draw(render, render.view);
		}
	    }
	    else if (render.cursor !== null) {
		var x = e.layerX - render.canvas.offsetLeft;
		var y = e.layerY - render.canvas.offsetTop;
		render.cursor.x = y;
		render.cursor.y = x;
		render.cursor.draw(render);
	    }
	}
    });
    $("#map").click(function(event) {
	if (render.gameEnd == false) {
	    var position = getPosition(event);
	    try {
		tools[render.tool](render, position.x, position.y);
	    }
	    catch (e) {
		console.log("no event found");
	    }
	}
    });

    $("#addObject").click(function () {
	if (render.gameEnd == false) {
	    changeView(render, "object");
	    render.tool = "addObject";
	    render.objectSelected = null;
	    render.canDrag = false;
	    render.map.draw(render, "object");
	    $("#config-tool").html(ConfObject(render));
	    render.cursor = new Cursor("circle", 20);
	    ControllerObject(render);
	}
    });

    $("#selectObject").click(function () {
	if (render.gameEnd == false) {
	    changeView(render, "full");
	    render.tool = "selectObject";
	    render.objectSelected = null;
	    render.canDrag = false;
	    $("#config-tool").html("");
	    render.map.draw(render, "full");
	    render.cursor = null;
	}
    });

    $("#addCollider").click(function () {
	if (render.gameEnd == false) {
	    changeView(render, "full");
	    render.canDrag = false;
	    render.tool = "addCollider";
	    render.map.draw(render, "full");
	    $("#config-tool").html(ConfCollider());
	    ControllerCollider(render);
	}
    });

    $("#moveObject").click(function () {
	if (render.gameEnd == false) {
	    changeView(render, "full");
	    render.canDrag = true;
	    $("#config-tool").html("");
	    render.tool = "moveObject";
	    render.map.draw(render, "full");
	    render.cursor = null;
	}
    });
    $("#addPlayer").click(function () {
	if (render.gameEnd == false) {
	    console.log("pla[");
	    changeView(render, "full");
	    render.canDrag = false;
	    $("#config-tool").html("");
	    render.tool = "addPlayer";
	    render.map.draw(render, "full");
	    render.cursor = new Cursor("circle", 20);
	}
    });
    $("#movePlayer").click(function () {
	if (render.gameEnd == false) {
	    changeView(render, "move_player");
	    render.canDrag = false;
	    $("#config-tool").html("");
	    render.tool = "movePlayer";
	    render.map.draw(render, render.view);
	    render.cursor = null;
	}
    });
    $("#throwBomb").click(function () {
	if (render.gameEnd == false) {
	    changeView(render, "throw_bomb");
	    $("#config-tool").html(ConfBomb(render));
	    render.canDrag = false;
	    ControllerBomb(render);
	    render.tool = "throwBomb";
	    render.map.draw(render, render.view);
	    render.cursor = null;
	}
    });
    $("#nextStep").click(function () {
	if (render.gameEnd == false) {
	    console.log("nextStep");
	    nextStep(render, socket);
	    $(this).attr('disabled', 'disabled');
	}
    });
}

$(document).ready(function () {
    init();
});
