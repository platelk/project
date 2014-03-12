##
## Makefile for Makefile in /home/platel_k/projet/minilibX/tp1
## 
## Made by kevin platel
## Login   <platel_k@epitech.net>
## 
## Started on  Wed Nov  9 12:58:27 2011 kevin platel
## Last update Mon Dec 12 10:28:52 2011 kevin platel
##

NAME	= mysh

LINK	= source/

SRC	= $(wildcard $(LINK)*.c)

OBJ	= $(SRC:.c=.o)

CC	= gcc

CFLAGS	= -I ./include/ -Wall -Wextra -g -Llib/ -lmy

all:	$(NAME)

%.o:	%.c
	cc -c $^ -o $@ -g -I include

$(NAME):	$(OBJ)
	make -C lib/
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:	fclean all
