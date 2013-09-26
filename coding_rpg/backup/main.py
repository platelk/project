#! /usr/bin/python3.2

import time
from user import *

def main():
    me = User("ozouf_h")
    while (1):
        print("---------------------------------------")
        print(me.help())
        x = input("cmd?")
        a = input("arg?")
        if (a == ""):
            print(me.functions[int(x)]())
        else:
            print(me.functions[int(x)](a))
        
#    time.sleep(1)
   # me.check_exo("/home/ozouf_h/src_file")
  #  time.sleep(1)
 #   me.check_exo("/home/ozouf_h/src_file")
#    time.sleep(1)
   # me.check_exo("/home/ozouf_h/src_file")
  #  time.sleep(1)
 #   me.check_exo("/home/ozouf_h/src_file")
#    time.sleep(1)
   # me.check_exo("/home/ozouf_h/src_file")
  #  time.sleep(1)
 #   me.check_exo("/home/ozouf_h/src_file")
#    time.sleep(1)
    #me.check_exo("/home/ozouf_h/src_file")
   # time.sleep(1)
  #  me.check_exo("/home/ozouf_h/src_file")
 #   time.sleep(1)
#    me.check_exo("/home/ozouf_h/src_file")
   # me.print_history()
  #  me.print_achievement()

if __name__ == '__main__':
    main()
