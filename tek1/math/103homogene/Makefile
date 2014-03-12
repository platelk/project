##
## makefile for tp1
##
## Made by matthieu przybylski
## Login   <przyby_m@epitech.net>
##
## Started on  Wed Nov  9 12:52:45 2011 matthieu przybylski
## Last update Thu Dec 15 16:57:02 2011 matthieu przybylski
##

CC      = gcc

RM      = rm -f

NAME    = 103homogene

LINK	= ./source/

OBJ	= $(SRC:.c=.o)

SRC   	= $(LINK)main.c \
	  $(LINK)parsing.c \
	  $(LINK)create_matrix.c \
	  $(LINK)mult_matrix.c \
	  $(LINK)init_result.c \
	  $(LINK)show_result.c \
	  $(LINK)transformations.c

CFLAGS = -I ./include -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	 @$(CC) -o $(NAME) $(OBJ) -lm
	 @echo "Make : succes"

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all