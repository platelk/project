##
## Makefile for Makefile in /home/platel_k/projet/minilibX/tp1
##
## Made by kevin platel
## Login   <platel_k@epitech.net>
##
## Started on  Wed Nov  9 12:58:27 2011 kevin platel
##


NAME		=	libbuilt.a

CD		=	cd/

LIB		=	-L ../../lib/ -lmy

LINK		=	src

LINK_INC	=	-I ../../include

CC		=	gcc
RM		=	rm -f

INC		=	-I $(LINK_INC)/

SRC		=	$(LINK)/is_builtin.c

OBJ		=	$(SRC:.c=.o)


CFLAGS		+=	-Wall -Werror -Wextra -O3 $(LIB) $(LINK_INC)
ifeq ($(DEBUG),yes)
	CFLAGS 	+=	-g
endif


all:		$(NAME)

%.o:		%.c
		$(CC) -c $^ -o $@ $(CFLAGS) $(LINK_INC) $(LIB)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@cp $(NAME) ../../lib

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

test:	all
	gcc -I ../../include -o test *.c -L . -lenv $(LIB) -g