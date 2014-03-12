##
## Makefile for xsys in /home/leprov_a//bdd/xsys
##
## Made by alexis leprovost
## Login   <leprov_a@epitech.net>
##
## Started on  Mon Apr 30 12:54:38 2012 alexis leprovost
##

NAME=	libmy.a

CFLAGS=	-Wall -I$(INC) -O3

SRC=	$(wildcard *.c ./my_printf/*.c)

OBJ=	$(SRC:.c=.o)

INC=	../inc/

RM=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
