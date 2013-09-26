
/////////////////////////////
// UTILS FUNCTIONS
/////////////////////////////

function	getValue(str) {
    var pos = str.search(":");
    var size = parseInt(str.substr(0, pos), 10);
    str = str.substr(pos + 1);
    if (isNaN(size))
	throw new Error("not a number");
    return ([str.substr(0, size), str.substr(size + 1)]);
}

function	getAttr(str) {
    var pos = str.search(":");
    var type = str.substr(0, pos);
    str = str.substr(pos + 1);
    pos = str.search(":");
    var size = parseInt(str.substr(0, pos), 10);
    if (isNaN(size))
	throw new Error("not a number");
    str = str.substr(pos + 1);
    var data = str.substr(0, size);
    var res;
    if (type == 'i')
	res = parseInt(data, 10);
    else if (type == 'f' || type == 'd')
	res = parseFloat(data);
    res = data;
    if (isNaN(res))
	throw new Error("bad type");
    return ([res, str.substr(size + 1)]);
}

/////////////////////////////
// PARSER
/////////////////////////////

function	parseGameObject(str) {
    var obj, data, li_comp;
    data = getValue(str);
    var name = data[0];
    str = data[1];
    data = getValue(str);
    var id = data[0];
    str = data[1];
    data = getValue(str);
    var component = data[0];
    str = data[1];
    if (component.length > 2) {
	if (component[0] != '{' || component[component.length - 1] != '}' || str !== "")
	    throw new Error("bad trame");
	li_comp = parseComponent(component.substr(1, component.length - 2));
    }
    return ([name, id, li_comp]);
}

function	parseComponent(str) {
    var data, li_attr, li_comp = [];
    while (str !== "") {
	li_attr = [];
	var pos = str.search(":");
	var type = str.substr(0, pos);
	if (type != "CP")
	    throw new Error("not a component");
	str = str.substr(pos + 1);
	data = getValue(str);
	var name = data[0];
	str = data[1];
	data = getValue(str);
	var attribute = data[0];
	str = data[1];
	if (attribute.length > 2) {
	    if (attribute[0] != '{' || attribute[attribute.length - 1] != '}')
		throw new Error("bad trame");
	    li_attr = parseAttribute(attribute.substr(1, attribute.length - 2));
	}
	li_comp.push([name, li_attr]);
    }
    return (li_comp);
}

function	parseAttribute(str) {
    var data, li_attr = [];
    while (str !== "") {
	data = getAttr(str);
	li_attr.push(data[0]);
	str = data[1];
    }
    return (li_attr);
}

function	routeGameObject(str) {
    var li;
    var pos = str.search(":");
    var type = str.substr(0, pos);
    if (type == "GO")
	li = parseGameObject(str.substr(pos + 1));
    else
	throw new Error("not a gameobject");
    return (li);
}

function	parse(str) {
    var objects = [];
    trame = str.split("|");
    for (var i = 0; i < trame.length; i++) {
	try {
	    if (trame[i] !== "")
		objects.push(routeGameObject(trame[i]));
	}
	catch (e) {
	    throw new Error("bad format");
	}
    }
    return (objects);
}

function	parseTCP(str) {
    try {
	var res = [], data;
	data = getValue(str);
	res.push(data[0]);
	data = getValue(data[1]);
	res.push(data[0]);
	data = getValue(data[1]);
	res.push(data[0]);
	data = getValue(data[1]);
	res.push(data[0]);
	data = getValue(data[1]);
	res.push(data[0]);
	data = getValue(data[1]);
	res.push(data[0]);
	return (res);
    }
    catch (e) {
	return (null);
    }
}

/////////////////////////////
// MODULE EXPORT
/////////////////////////////

exports.parse = parse;
exports.parseTCP = parseTCP;
