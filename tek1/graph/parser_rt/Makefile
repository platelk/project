##
## Makefile for Makefile in /home/platel_k/projet/minilibX/tp1
##
## Made by kevin platel
## Login   <platel_k@epitech.net>
##
## Started on  Wed Nov  9 12:58:27 2011 kevin platel
##

NAME	= rt

LINK	= parser/

SRC	= $(wildcard $(LINK)*.c)

OBJ	= $(SRC:.c=.o)

CC	= colorgcc

CFLAGS	= -I includes/ -Wall -Wextra  -lm -L/usr/X11/lib -lXext -lX11 -lmlx -Lmy/ -lmy

all:	$(NAME)

%.o:	%.c
	$(CC) -c $^ -o $@ -g -I includes -I /usr/X11/include -Wall -Wextra -W

$(NAME):	$(OBJ)
	make -C my/
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:	fclean all