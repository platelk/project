##
## Makefile for Makefile in /home/platel_k/projet/minilibX/tp1
##
## Made by kevin platel
## Login   <platel_k@epitech.net>
##
## Started on  Wed Nov  9 12:58:27 2011 kevin platel
##

NAME_VM		= 	  corewar

ifndef ($(DEBUG))
	DEBUG	=	no
endif

ifndef ($(MOUV))
	MOUV 	=	../../
endif

LINK_VM_STRUCT	= source/struct/

LINK_VM_MNEMOS	= source/struct/mnemoniques/

LINK_VM_CHECK	= source/check/

LINK_VM_SOUND	= source/sound/

LINK_VM_GAME	= source/game/

LINK_VM_GRAPH	= source/graph/

LINK_VM_IMG	= source/image/

LINK_VM_FREE	= source/free/


SRC_VM	= 	  $(wildcard $(LINK_VM_STRUCT)*.c $(LINK_VM_MNEMOS)*.c $(LINK_VM_CHECK)*.c $(LINK_VM_GAME)*.c $(LINK_VM_FREE)*.c $(LINK_VM_SOUND)*.c $(LINK_VM_IMG)*.c $(LINK_VM_GRAPH)*.c) \
	  	  source/main.c \
		  source/op.c

OBJ_VM	=	  $(SRC_VM:.c=.o)

CC	= 	  gcc -lm

INCLUDE	=	  -I ../../include/vm/ -I ../../include/vm/fmod

ifndef ($(FMOD))
	FMOD 	=    	  ./../../lib/fmod/libfmodex64-4.38.06.so
endif

LIB_FMOD=	  /tmp/libfmodex64-4.38.06.so
LIB	=	  -L../../lib/ -lmy
LIB_SDL	=	  -L../../lib/ -lmy $(SDL) $(LIB_FMOD)

CFLAGS	= 	  -Wall -Wextra

SDL	=	  -lSDL_ttf -lSDL_image -lSDL_net
CC_SDL	=	  gcc `sdl-config --libs` -g

THREAD	=	  -lpthread

ifeq ($(DEBUG),yes)
	CFLAGS += -g
endif


all:		$(NAME_VM)

%.o:		%.c
		$(CC) -c $^ -o $@ $(INCLUDE) $(LIB) $(CFLAGS)

$(NAME_VM):	$(OBJ_VM)
		cp $(FMOD) /tmp
		make -C ../../lib/
		$(CC_SDL) -lm $(THREAD) -o $(NAME_VM) $(OBJ_VM) $(INCLUDE) $(LIB_SDL) $(CFLAGS)
#		mv $(NAME_VM) $(MOUV)

clean:
		rm -f $(OBJ_VM)

fclean:		clean
		rm -f $(NAME_VM)

re:		fclean all