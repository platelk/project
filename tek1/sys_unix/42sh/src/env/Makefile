##
## Makefile for Makefile in /home/platel_k/projet/minilibX/tp1
##
## Made by kevin platel
## Login   <platel_k@epitech.net>
##
## Started on  Wed Nov  9 12:58:27 2011 kevin platel
##


NAME		=	libenv.a

ENV		=	yes
ALI		=	yes
ERROR		=	yes
DEBUG		=	yes

LIB		=	-L ../my/ -lmy

LINK		=	src

LINK_INC	=	../../include

CC		=	gcc

RM		=	rm -f

INC		=	-I $(LINK_INC)/

SRC		=	$(LINK)/env.c \
			$(LINK)/search_env.c \
			$(LINK)/export_env.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Werror -Wextra -O3 $(LIB) $(INC)

ifeq ($(DEBUG),yes)
	CFLAGS 	+=	-g
endif

all:		$(NAME)

%.o:		%.c
		$(CC) -c $^ -o $@ $(CFLAGS)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
# @cp $(NAME) ../../lib/

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

test:	all
	gcc -I ../../include -o test *.c -L ../../lib -lenv $(LIB) -g
