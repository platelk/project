##
## Makefile for cat in /home/platel_k//projet/piscine/Jour_13/cat
##
## Made by kevin platel
## Login   <platel_k@epitech.net>
##
## Started on  Wed Oct 26 11:06:21 2011 kevin platel
##

NAME	= cat

SRC	= main.c \
	read_file.c \
	error.c

all:	$(NAME)

$(NAME):
	cc -I ~/lib/ -o $(NAME) $(SRC) -L ~/lib -lmy

clean:
	rm -f $(OBJ)

fclean: 	clean
	rm -f $(NAME)

re:	fclean clean
