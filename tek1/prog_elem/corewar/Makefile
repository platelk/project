##
## Makefile for Makefile in /home/platel_k/projet/minilibX/tp1
##
## Made by kevin platel
## Login   <platel_k@epitech.net>
##
## Started on  Wed Nov  9 12:58:27 2011 kevin platel
## Last update Sun Jan 22 14:52:50 2012 kevin platel
##

NAME	= 	  AsmX

LINK_ASM_DATA	= source/ASM/data/

LINK_ASM_FILE	= source/ASM/write/

SRC	= 	  $(wildcard $(LINK_ASM_DATA)*.c $(LINK_ASM_FILE)*.c) \
	  	  source/ASM/main.c

OBJ	= 	  $(SRC:.c=.o)

CC	= 	  gcc

INCLUDE	=	  -I ./include/

LIB	=	  -Llib/ -lmy

CFLAGS	= 	  -Wall -Wextra -W

all:		$(NAME)

%.o:		%.c
		cc -c $^ -o $@ $(INCLUDE) $(CFLAGS) $(LIB)

$(NAME):	$(OBJ)
		make -C lib/
		$(CC) -o $(NAME) $(OBJ) $(INCLUDE) $(LIB) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all