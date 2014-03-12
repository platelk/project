##
## Makefile for Makefile in /home/platel_k/projet/minilibX/tp1
##
## Made by kevin platel
## Login   <platel_k@epitech.net>
##
## Started on  Wed Nov  9 12:58:27 2011 kevin platel
##

ASM		= yes
VM		= yes

DIR_ASM		= data/asm

DIR_VM		= data/vm

DEBUG		= no

MOUV		= ../../

#FMOD		= ./lib/fmod/libfmodex64-4.38.06.so

all:
ifeq ($(ASM),yes)
	make -C $(DIR_ASM)  DEBUG=$(DEBUG) MOUV=$(MOUV)
endif
ifeq ($(VM),yes)
	make -C $(DIR_VM)   DEBUG=$(DEBUG) MOUV=$(MOUV) #FMOD=$(FMOD)
endif

clean:
ifeq ($(ASM),yes)
		make clean -C $(DIR_ASM)
endif
ifeq ($(VM),yes)
		make clean -C $(DIR_VM)
endif

fclean:
ifeq ($(ASM),yes)
		make fclean -C $(DIR_ASM)
endif
ifeq ($(VM),yes)
		make fclean -C $(DIR_VM)
endif

re:		fclean all