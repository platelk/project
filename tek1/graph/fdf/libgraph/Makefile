##
## Makefile for Makefile in /home/platel_k//projet/piscine/Jour_11
## 
## Made by kevin platel
## Login   <platel_k@epitech.net>
## 
## Started on  Mon Oct 24 08:56:33 2011 kevin platel
## Last update Mon Dec 19 10:27:26 2011 kevin platel
##

LINK=	c/

SRC	= $(wildcard $(LINK)*.c)

OBJ	= $(SRC:.c=.o)

NAME	= libmygraph.a

RM	= rm -f

CFLAGS	= -I ./include/ -Wall -Wextra -g -Llib/ -lmy -L/usr/lib64 -lmlx_x86_64-linux -L/usr/lib64/X11 -lXext -lX11

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)