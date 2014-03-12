##
## Makefile for Makefile in /home/platel_k/projet/my_printf
## 
## Made by kevin platel
## Login   <platel_k@epitech.net>
## 
## Started on  Wed Nov  9 10:22:25 2011 kevin platel
## Last update Sun Nov 27 10:05:02 2011 kevin platel
##

NAME	= marvin

LINK	= source/

SRC	= $(LINK)main.c \
	  $(LINK)my_str_to_wordtabmod.c \
	  $(LINK)detect_param.c \
	  $(LINK)freewordtab.c \
	  $(LINK)declar.c \
	  $(LINK)my_new_str_to_wordtab.c \
	  $(LINK)main_loop.c \
	  $(LINK)gest_error.c \
	  $(LINK)gest_error_src.c

OBJ	= $(SRC:.c=.o)

CFLAGS	= -Wextra -ansi -Wall -I ./include/

all:		$(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ) -L lib/lib/ -lmy

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)