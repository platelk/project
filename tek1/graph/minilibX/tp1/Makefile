##
## Makefile for Makefile in /home/platel_k/projet/minilibX/tp1
## 
## Made by kevin platel
## Login   <platel_k@epitech.net>
## 
## Started on  Wed Nov  9 12:58:27 2011 kevin platel
## Last update Wed Nov  9 13:09:44 2011 kevin platel
##

NAME	= tp1

SRC	= *.c

CC	= gcc -I $(INCLUDE) -o

CCFLAGS	= -Wall -Wextra

LIB	= -L/usr/lib64 -lmlx_$HOSTTYPE -L/usr/lib64/X11 -lXext -lX1

all:	$(NAME)

$(NAME):	
	$(CC) $(SRC) $(NAME) $(CCFLAGS) $(LIB)

clean:
	rm -f $(NAME)