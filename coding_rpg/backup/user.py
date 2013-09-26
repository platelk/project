#! /usr/bin/python3.2

import sys
from mouli import *
from tip import *
class User:
    def __init__(self, login, a_id = -1):
        self.id = a_id
        self.name = login
        self.lvl = 0
        self.score = 0
        self.credit = 100
        self.history = list()
        self.achievement = list()
        self.current_exo = Exo("python", "exo0", 0)
        self.nbr_check_fail = 0
        self.nbr_check_success = 0
        self.nbr_perfect = 0
        self.tips = Tips()
        self.current_lang = "python"
        self.functions = [
            self.list_tips,
            self.list_my_tips,
            self.buy_tip,
            self.print_score,
            self.print_credit,
            self.print_history,
            self.print_achievement,
            self.check_exo,
            self.get_params,
            self.get_subject
            ]

    def help(self):
        message = ""
        message += "0. list_tips\n"
        message += "1. list_my_tips\n"
        message += "2. buy_tips\n"
        message += "3. print_score\n"
        message += "4. print_credit\n"
        message += "5. print_history\n"
        message += "6. print_achievement\n"
        message += "7. check_exo\n"
        message += "8. get_params\n"
        message += "9. get_subject\n"
        return (message)

    def get_params(self):
        s = "::".join(self.current_exo.get_params())
        s = s.replace("\n", '')
#        s = s.replace('"', '')
        print s
        return s

    def list_tips(self):
        return (self.tips.list_tips())

    def list_my_tips(self):
        return (self.tips.list_my_tips())

    def buy_tip(self, id_tip):
        try:
            x = self.tips.tip_list[int(id_tip)].cost
        except:
            return ("Error: id_tip do not exist\n.")
        if (int(self.credit) >= int(x)):
            self.credit -= int(x)
            return (self.tips.buy_tip(int(id_tip)))
        else:
            return ("not enough credit, try it later\n.")

    def print_score(self):
        return ("Your score: " + str(self.score) + "\n")

    def print_credit(self):
        return ("You have : " + str(self.credit) + " credits\n")

    def print_history(self):
        message = ""
        for i in self.history:
            message += i.print_res()
        return (message)

    def check_exo(self, content):
        if (self.current_exo.check(content)):
            message = "Check " + self.current_exo.get_name() + ":\tSuccess\n"
            self.lvl += 1
            self.score += self.lvl
            self.credit += self.lvl
            if (self.current_exo.nbr_try == 1):
                self.nbr_perfect += 1
            self.history.append(self.current_exo)
            self.print_score()
            if (self.lvl < nbr_exo):
                self.current_exo.newSubject(self.current_exo.section, self.current_exo.exoId + 1)
            self.nbr_check_success += 1
        else:
            self.nbr_check_fail += 1
            message = "Check " + self.current_exo.get_name() + ":\tFail\n"
        self.check_achievement()
        return (message)

    def get_result_exo(self, id_exo):
        if (id_exo < self.lvl):
            return (self.history[id_exo].print_res())
        else:
            return ("exo" + str(id_exo) + " not solved\n")

    def check_achievement(self):
        if (self.current_exo.nbr_try > 10 and not("bruteforcer" in self.achievement)):
            self.achievement.append("bruteforcer")
        if (self.nbr_perfect > 0 and not("perfect" in self.achievement)):
            self.achievement.append("perfect")
        if (self.lvl == 1 and not("newbee" in self.achievement)):
            self.achievement.append("newbee")
        if (self.lvl == 2 and not("newbee [*]" in self.achievement)):
            self.achievement.append("newbee [*]")
        if (self.lvl == 4 and not("newbee [**]" in self.achievement)):
            self.achievement.append("newbee [**]")
        if (self.lvl == 6 and not("newbee [***]" in self.achievement)):
            self.achievement.append("newbee [***]")

    def print_achievement(self):
        a_id = 0
        message = ""
        for i in self.achievement:
            message += str(a_id) + ". " + i + "\n"
            a_id += 1
        return (message)
    def get_subject(self):
        return self.current_exo.get_subject()