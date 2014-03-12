##
## Makefile for Makefile in /home/platel_k/projet/my_printf
## 
## Made by kevin platel
## Login   <platel_k@epitech.net>
## 
## Started on  Wed Nov  9 10:22:25 2011 kevin platel
## Last update Sun Dec 11 12:43:25 2011 kevin platel
##

NAME	= 102matrice

LINK	= source/

SRC	= $(wildcard $(LINK)*.c)

OBJ	= $(SRC:.c=.o)

CFLAGS	= -Wextra -ansi -Wall -I include

all:	$(NAME)

%.o:	%.c
	cc -c $^ -o $@ -g -I include

$(NAME):	$(OBJ)
	make -C lib/
	cc -o $(NAME) $(OBJ) -L lib/ -lmy -g

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:	fclean all