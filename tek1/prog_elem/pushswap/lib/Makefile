##
## Makefile for Makefile in /afs/epitech.net/users/epitech_2016/leprov_a/rendu/lib/my
##
## Made by alexis leprovost
## Login   <leprov_a@epitech.net>
##
## Started on  Mon Oct 24 09:32:32 2011 alexis leprovost
## Last update Thu Apr  5 11:11:06 2012 ronan guiho
##

NAME=	libmy.a

INC=	my.h

RM=	rm -f

SRC=	$(wildcard *.c)

OBJ=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) *#

fclean:	clean
	$(RM) $(NAME)

re:	fclean all clean
