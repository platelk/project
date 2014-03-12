NAME	=	my_mastermind

LINK	=	src/

INC	=	-I inc/

SRC	=	$(LINK)/main.c \
		$(LINK)/game.c \
		$(LINK)/my_get_nbr.c \
		$(LINK)/my_putnbr.c \
		$(LINK)/my_rand_code.c \
		$(LINK)/verif_piont.c \
		$(LINK)/check_game.c \
		$(LINK)/msg.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra

all:	$(NAME)

%.o:	%.c
	gcc -c $^ -o $@ $(INC)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(INC)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all