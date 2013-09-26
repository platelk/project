#! /bin/python3.3

TRAME_SEP = ":"
TRAME_ARG = ";"
TRAME_NBR_ELM = 6
TRAME_OBJECT_B = "{"
TRAME_OBJECT_E = "}"

class   Trame:
    def __init__(self, args):
        self.ready_to_serialize = False
        if len(args) == 1:
            self.unserialize(args[0])
        elif len(args) == TRAME_NBR_ELM:
            self.__fill_args(args)
        else:
            raise Exception ("must have 1 or 6 arguments (serialized/unserialized)")
 
    def __getNextSize(self, s):
        pos = s.find(TRAME_SEP)
        if pos == -1:
            raise SyntaxError("missing separator " + TRAME_SEP)
        try:
            return (int(s[0:pos]), len(s[0:pos]))
        except ValueError:
            raise SyntaxError("size is not a number")
        
    def __getNextArg(self, s):
        size = self.__getNextSize(s)
        arg = s[size[1] + 1: size[1] + size[0] + 1]
        if len(arg) != size[0]:
            raise SyntaxError("missing letters")
        return (arg, size[1] + 1 + len(arg))

    def unserialize(self, s):
#atttendtion p[enser a faire un try catch
        ac = 0
        self.launcher_id, pos = self.__getNextArg(s); ac += pos + 1
        self.event_name, pos = self.__getNextArg(s[ac:]); ac += pos + 1
        self.launcher_type, pos = self.__getNextArg(s[ac:]); ac += pos + 1
        self.target_type, pos = self.__getNextArg(s[ac:]); ac += pos + 1
        self.target_id, pos = self.__getNextArg(s[ac:]); ac += pos + 1
        data_size = self.__getNextSize(s[ac:])
        self.args = s[ac + data_size[1] + 1:ac + data_size[1] + data_size[0] + 1]
        ac += len(self.args)
        if len(s[ac + data_size[1] + data_size[0] + 1:]) != 0:
            raise SyntaxError("to much argument in trame")
        self.ready_to_serialize = True

    def __fill_args(self, li):
        self.launcher_id = li[0]
        self.event_name = li[1]
        self.launcher_type = li[2]
        self.target_type = li[3]
        self.target_id = li[4]
        self.args = li[5]
        self.ready_to_serialize = True

    def serialize(self):
        if self.ready_to_serialize == True:
            ser = str(len(self.launcher_id)) + TRAME_SEP + self.launcher_id + TRAME_ARG
            ser += str(len(self.event_name)) + TRAME_SEP + self.event_name + TRAME_ARG
            ser += str(len(self.launcher_type)) + TRAME_SEP + self.launcher_type + TRAME_ARG
            ser += str(len(self.target_type)) + TRAME_SEP + self.target_type + TRAME_ARG
            ser += str(len(self.target_id)) + TRAME_SEP + self.target_id + TRAME_ARG
            ser += str(len(self.args)) + TRAME_SEP + self.args
            return (ser)
        else:
            raise RuntimeError("not ready to serialize")

    def __getNameGameObject(self, s):
        pos = s.find(TRAME_SEP)
        if pos == -1:
            raise SyntaxError("Game object bad format")
        return (s[0:pos])

    def __getType(data):
        if data == "":
            return (None, 0)
        pos = data.find(TRAME_SEP)
        if pos == -1:
            raise SyntaxError("can't find a type")
        return ((data[0:pos], pos))

    def __getValueFromType(t, data):
        pos = data.find(TRAME_SEP)
        if pos == -1:
            raise SyntaxError("cant find separator")
        size = int(data[0:pos])
        value = data[pos + 1:pos + size + 1]
        res = None
        if t == "int":
            res = int(value)
        elif t == "float":
            res = float(value)
        elif t == "string":
            res = value
        else:
            raise SyntaxError("unknown type" + t)
        return (res, pos + size + 2)

    def __prepare_parse_gameobject(data):
        pos = data.find(TRAME_SEP)
        if pos == -1:
            raise SyntaxError("cant find separator")
        size = int(data[0:pos])
        value = data[pos + len(str(size)):pos + size + len(str(size))]
        cur = pos + len(str(size)) + size + 1
        data_len = data[cur:].find(TRAME_SEP)
        if pos == -1:
            raise SyntaxError("cant find separator")
        data_len_size = int(data[cur:cur + data_len])
        cur += data_len + 1
        id_unique = data[cur:cur + data_len_size]
        cur += data_len_size + 1
        sub_len_pos = data[cur:].find(TRAME_SEP)
        sub_len = int(data[cur: cur + sub_len_pos])
        cur += sub_len_pos + 1
        sub_str = data[cur:cur + sub_len]
        if len(sub_str) > 0 and sub_str[0] == '{' and sub_str[len(sub_str) - 1] == '}':
            return (value, id_unique, sub_str[1:-1], cur + sub_len)
        raise SyntaxError("missing brackets")


    def __prepare_parse_gamecomponent(data):
        pos = data.find(TRAME_SEP)
        if pos == -1:
            raise SyntaxError("cant find separator")
        size = int(data[0:pos])
        pos += 1
        value = data[pos:pos + size]
        cur = pos + size + 1
        data_len = data[cur:].find(TRAME_SEP)
        if pos == -1:
            raise SyntaxError("cant find separator")
        if data[cur:cur + data_len] == "":
            return (value, "", cur + data_len)
        data_len_size = int(data[cur:cur + data_len])
        cur += data_len + 1
        sub_str = data[cur:cur + data_len_size]
        if len(sub_str) > 0 and sub_str[0] == '{' and sub_str[len(sub_str) - 1] == '}':
            return (value, sub_str[1:-1], cur + len(sub_str))
        raise SyntaxError("missing brackets")

    @staticmethod
    def unserializeObject(data):
        try:
            elms = []
            pos = 0
            while True:
                inc = 0
                t, inc = Trame.__getType(data[pos:])
                pos += inc + 1
                if t == None:
                    break
                if t == "i":
                    value, inc = Trame.__getValueFromType("int", data[pos:])
                    elms.append((None, value))
                elif t == "f" or t == "d":
                    value, inc = Trame.__getValueFromType("float", data[pos:])
                    elms.append((None, value))
                elif t == "s":
                    value, inc = Trame.__getValueFromType("string", data[pos:])
                    elms.append((None, value))
                elif t == "GO":
                    name, id_unique, new_data, cur = Trame.__prepare_parse_gameobject(data[pos:])
                    value, inc = Trame.unserializeObject(new_data)
                    elms.append(("GameObject", (name, id_unique, value)))
                    inc += cur
                elif t == "CP":
                    name, new_data, len_data = Trame.__prepare_parse_gamecomponent(data[pos:])
                    value, inc = Trame.unserializeObject(new_data)
                    elms.append(("Component", (name, value)))
                    inc = len_data + 1
                else:
                    raise SyntaxError("Unknow type" + t)
                pos += inc
            return (elms, pos)
        except (SyntaxError, LookupError, ValueError):
            raise SyntaxError("bad format")
