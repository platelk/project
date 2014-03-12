##
## Makefile for Makefile in /home/platel_k/projet/minilibX/tp1
## 
## Made by kevin platel
## Login   <platel_k@epitech.net>
## 
## Started on  Wed Nov  9 12:58:27 2011 kevin platel
##

NAME	= my_select

LINK	= source/

SRC	= $(wildcard $(LINK)*.c)

OBJ	= $(SRC:.c=.o)

CC	= gcc

CFLAGS	= -I ./include/ -Wall -Wextra -Llib/ -lmy -lncurses -ltermcap -ltcl8.5

all:	$(NAME)

%.o:	%.c
	cc -c $^ -o $@ -g -I include -Wall -Wextra -W

$(NAME):	$(OBJ)
	make -C lib/
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:	fclean all