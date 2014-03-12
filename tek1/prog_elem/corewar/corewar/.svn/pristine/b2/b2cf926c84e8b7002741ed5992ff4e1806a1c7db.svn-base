##
## Makefile for Makefile in /home/platel_k/projet/minilibX/tp1
##
## Made by kevin platel
## Login   <platel_k@epitech.net>
##
## Started on  Wed Nov  9 12:58:27 2011 kevin platel
##

NAME_ASM	= 	asm

ifndef ($(DEBUG))
	DEBUG		=	no
endif

ifndef ($(MOUV))
	MOUV 	= 	../../
endif

LINK_ASM_DATA	= source/data/

LINK_ASM_FILE	= source/write/

LINK_ASM_ERRORS = source/errors/

SRC_ASM	= 	  $(wildcard $(LINK_ASM_DATA)*.c $(LINK_ASM_FILE)*.c $(LINK_ASM_ERRORS)*.c) \
	  	  source/main.c \
		  source/op.c \
		  source/asm.c

OBJ_ASM	= 	  $(SRC_ASM:.c=.o)

CC	= 	  gcc -g

INCLUDE	=	  -I ../../include/asm/

LIB	=	  -L../../lib/ -lmy

CFLAGS	= 	  -Wall -Wextra

ifeq ($(DEBUG),yes)
	CFLAGS += -g
endif

all:		$(NAME_ASM)

%.o:		%.c
		cc -c $^ -o $@ $(INCLUDE) $(CFLAGS) $(LIB)

$(NAME_ASM):	$(OBJ_ASM)
		make -C ../../lib/
		$(CC) -o $(NAME_ASM) $(OBJ_ASM) $(INCLUDE) $(LIB) $(CFLAGS)
#		mv $(NAME_ASM) $(MOUV)

clean:
		rm -f $(OBJ_ASM)

fclean:		clean
		rm -f $(NAME_ASM)

re:		fclean all