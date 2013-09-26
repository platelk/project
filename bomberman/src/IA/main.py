#!/usr/bin/python3.3

import  sys
import  Bot

def     usage():
    print("[USAGE]: " + sys.argv[0] + " host port [serialize] [step].")

def     main():
    print("IA LAUNCHED with [", sys.argv , "]")
    if len(sys.argv) >= 3:
        host = sys.argv[1]
        port = sys.argv[2]
        step = False
        serialized_ia = None;
        if len(sys.argv) == 4 and sys.argv[3] == "step":
            step = True
        elif len(sys.argv) == 5 and sys.argv[4] == "step":
            step = True
            serialized_ia = sys.argv[3];
        elif len(sys.argv) == 4:
            serialized_ia = sys.argv[3];
        print("[INFO]: try to connect to " + host + " on " + port)
        bot = Bot.Bot(host, int(port), step, serialized_ia)
        bot.update()
    else:
        print("[Error] missing arguments.")
        usage()

if __name__ == "__main__":
    main()
