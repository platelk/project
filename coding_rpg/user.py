#! /usr/bin/python3.2

import sys
from language import *
from exo import *

class User:
    def __init__(self, login, a_id):
        self.id = a_id
        self.name = login
        self.credit = 1000
        self.language = list()
        self.current_language = None
        self.functions = [
            self.help,
            self.check_exo,
            self.select_language,
            self.list_language,
            self.get_my_lvls,
            self.get_my_points,
            self.list_my_tips,
            self.list_tips,
            self.get_tips,
            self.get_my_credit,
            self.buy_tips,
            self.add_language,
            self.show_current_language,
            self.show_current_exo,
            self.list_lesson,
            self.get_lesson,
            self.get_params,
            self.adminCmd
            ]

    def adminCmd(self, param, user):
        print("Param -- {} -- {}".format(param, param[3:]))
        i = 0
        print("i = {} {}".format(i, user))
        print("User recup is ======>>>> {} {}".format(user[i].name, param[2]))
        print("Exec func")
        if int(param[2]) == 20:
            user[i].credits += int(param[2])
        elif int(param[2]) == 21:
            user[i].current_language.next_exo()
        elif int(param[2]) == 22:
            user[i].current_language.prev_exo()
        else:
            print("alone")
            y, i = user[i].function[int(param[2])](*param[3:])
            print("== {} == {} ==".format(y, i))


    def setFunction(self):
        self.functions = [
            self.help,
            self.check_exo,
            self.select_language,
            self.list_language,
            self.get_my_lvls,
            self.get_my_points,
            self.list_my_tips,
            self.list_tips,
            self.get_tips,
            self.get_my_credit,
            self.buy_tips,
            self.add_language,
            self.show_current_language,
            self.show_current_exo,
            self.list_lesson,
            self.get_lesson,
            self.get_params
            ]

    def help(self):
        message = "0. help\n"
        message += "1. check_exo\n"
        message += "2. select_language\n"
        message += "3. list_language\n"
        message += "4. get_my_lvls\n"
        message += "5. get_my_points\n"
        message += "6. list_my_tips\n"
        message += "7. list_tips\n"
        message += "8. get_tips\n"
        message += "9. get_my_credit\n"
        message += "10. buy_tips\n"
        message += "11. add_language\n"
        message += "12. show_current_language\n"
        message += "13. show_current_exo\n"
        message += "14. list_lesson\n"
        message += "15. get_lesson\n"
        message += "16. get_params\n"
        return (message)


    def add_language(self, name, id=0):
        #try:
            self.language.append(Language(name, name + "_conf.xml", id))
            return (EXIT_SUCCESS, "language loaded successfully")
        #except:
            return (NO_INSTANCED, "language not found")

    def refresh_exo(self):
        for l in self.language:
            l.refresh_exo()

    def check_exo(self, content):
        print("enter...")
        if (self.current_language is not None):
            ex, res = self.current_language.check_exo(content)
            if (ex == EXIT_SUCCESS):
                self.credit += self.current_language.get_credit()
                self.current_language.next_exo()
                return (EXIT_SUCCESS, "Congratulation")
            elif (ex == NO_INSTANCED):
                return (EXIT_FAILURE, "no more exercice are available")
            else:
                return (EXIT_FAILURE, res)
        return (NO_INSTANCED, "unspecified language")

    def select_language(self, id):
        try:
            self.current_language = self.language[int(id)]
            return (EXIT_SUCCESS, "You selected " + self.current_language.get_name()[1])
        except:
            return (EXIT_FAILURE, "This language does not exist")

    def list_language(self):
        text = ""
        for i, l in enumerate(self.language):
            text += str(i) + ". " + l.get_name()[1] + "\n"
        return (EXIT_SUCCESS, text)

    def get_my_lvls(self):
        text = ""
        for l in self.language:
            text += l.get_name()[1] + "\t[" + str(l.get_lvl()[1]) + "]\n"
        return (EXIT_SUCCESS, text)

    def get_my_credit(self):
        return (EXIT_SUCCESS, "you have " + str(self.credit) + " credits")

    def get_params(self):
        if (self.current_language is not None):
            return (self.current_language.get_params())
        else:
            return (NO_INSTANCED, "unspecified language")

    def get_my_points(self):
        text = ""
        total = 0
        for i in self.language:
            text = i.get_name()[1] + ":\t" + str(i.get_points()[1]) + " points\n"
            total += i.get_points()[1]
        text += "\nTOTAL:\t" + str(total) + "\n"
        return (EXIT_SUCCESS, text)

    def list_my_tips(self):
        if (self.current_language is not None):
            return (EXIT_SUCCESS, self.current_language.list_my_tips()[1])
        else:
            return (NO_INSTANCED, "unspecified language")

    def list_tips(self):
        if (self.current_language is not None):
            return (EXIT_SUCCESS, self.current_language.list_tips()[1])
        else:
            return (NO_INSTANCED, "unspecified language")

    def get_tips(self, id):
        if (self.current_language is not None):
            return (self.current_language.get_tips(int(id)))
        else:
            return (NO_INSTANCED, "unspecified language")

    def buy_tips(self, id):
        if (self.current_language is not None):
            res = self.current_language.buy_tips(int(id))
            if (res[0] == EXIT_SUCCESS):
                self.credit -= res[1]
                return (res[0], "operation success")
            else:
                return (res)
        else:
            return (NO_INSTANCED, "unspecified language")

    def show_current_language(self):
        if (self.current_language is not None):
            return (EXIT_SUCCESS, "Language: you studying " + self.current_language.get_name()[1])
        return (EXIT_FAILURE, "unspecified language")

    def show_current_exo(self):
        if (self.current_language is not None):
            return (EXIT_SUCCESS, "Exo: you studying " + self.current_language.get_current_exo()[1])
        return (EXIT_FAILURE, "unspecified language")

    def get_lesson(self, id):
        if (self.current_language is not None):
            return (self.current_language.get_lesson(id))
        return (NO_INSTANCED, "unspecified language")

    def list_lesson(self):
        if (self.current_language is not None):
            return (self.current_language.list_lesson())
        return (NO_INSTANCED, "unspecified language")
