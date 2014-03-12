##
## Makefile for Makefile in /home/platel_k/projet/minilibX/tp1
##
## Made by kevin platel
## Login   <platel_k@epitech.net>
##
## Started on  Wed Nov  9 12:58:27 2011 kevin platel
##


NAME		=	libglobing.a

ENV		=	yes
ALI		=	yes
ERROR		=	yes
DEBUG		=	yes

LINK		=	globing
LINK_ENV	=	glob_env
LINK_ALI	=	glob_alias
LINK_ERROR	=	glob_error

LINK_INC	=	../../include/

LIB		=	-L ../my -lmy -L ../env -lenv

CC		=	gcc
RM		=	rm -f

INC		=	-I $(LINK_INC)

SRC		=	$(LINK)/globing.c \
			$(LINK)/glob_list.c \
			$(LINK)/utils.c \
			glob_env/globing_env.c

ifeq ($(ENV),yes)
	SRC		+=	$(LINK_ENV)/globing_env.c
endif
##ifeq ($(ALI),yes)
##	SRC		+=	$(wildcard $(LINK_ALI)/*.c)
##endif
##ifeq ($(ERROR),yes)
##	SRC		+=	$(wildcard $(LINK_ERROR)/*.c)
##endif

OBJ		=	$(SRC:.c=.o)


CFLAGS		+=	-Wall -Werror -Wextra -O3 $(LIB)
ifeq ($(DEBUG),yes)
	CFLAGS 	+=	-g
endif


all:		$(NAME)

%.o:		%.c
		$(CC) -c $^ -o $@ $(CFLAGS) $(INC) $(LIB)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
# @cp $(NAME) ../../lib

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

test:	all
	gcc -I ../../include -o test main.c -L ../../lib -lglobing $(LIB) -L ../parsing -lpars