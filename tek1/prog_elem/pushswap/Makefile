##
## Makefile for Makefile in /home/platel_k/projet/minilibX/tp1
##
## Made by kevin platel
## Login   <platel_k@epitech.net>
##
##

NAME	= push_swap

LINK	= source/

SRC	= $(wildcard $(LINK)*.c)

OBJ	= $(SRC:.c=.o)

CC	= gcc

CFLAGS	= -I include/ -Wall -Wextra -Llib/ -lmy -O3 -ffast-math

all:	$(NAME)

%.o:	%.c
	cc -c $^ -o $@ -I include -W -Wall -Wextra

$(NAME):	$(OBJ)
	make -C lib/
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:	fclean all
