##
## Makefile for colle in /home/fontai_t/colle2
## 
## Made by thomas fontaine
## Login   <fontai_t@epitech.net>
## 
## Started on  Thu Apr 26 21:16:03 2012 thomas fontaine
##

CC	=	gcc

LINK	=	src

INC	=	include

CFLAGS	+=	-Wall -Wextra -I $(INC)

NAME	=	sand_pile

SRC	=	$(LINK)/main.c \
		$(LINK)/put.c \
		$(LINK)/count.c	\
		$(LINK)/check.c \
		$(LINK)/alloc.c \
		$(LINK)/get.c \
		$(LINK)/sand_pile.c \
		$(LINK)/print.c \
		$(LINK)/calc_size.c \
		$(LINK)/run_simulation.c \
		$(LINK)/my_free_tab.c

OBJ=	$(SRC:.c=.o)

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
