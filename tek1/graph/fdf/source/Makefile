##
## Makefile for Makefile in /home/platel_k/projet/minilibX/tp1
## 
## Made by kevin platel
## Login   <platel_k@epitech.net>
## 
## Started on  Wed Nov  9 12:58:27 2011 kevin platel
## Last update Sun Dec 11 12:43:16 2011 kevin platel
##

NAME	= fdf

LINK	= source/

SRC	= $(wildcard $(LINK)*.c)

OBJ	= $(SRC:.c=.o)

CC	= gcc

CFLAGS	= -I ./include/ -Wall -Wextra -g -Llib/ -lmy -L/usr/lib64 -lmlx_x86_64-linux -L/usr/lib64/X11 -lXext -lX11

all:	$(NAME)

%.o:	%.c
	cc -c $^ -o $@ -g -I include

$(NAME):	$(OBJ)
	make -C lib/
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:	fclean all