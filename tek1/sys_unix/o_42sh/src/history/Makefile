##
## Makefile for make in /home/phalip_z//exos/projets/minishell1/TP
## 
## Made by zoe phalippou
## Login   <phalip_z@epitech.net>
## 
## Started on  Tue Dec 13 13:47:39 2011 zoe phalippou
## Last update Wed Apr 18 21:10:40 2012 zoe phalippou
##

RM =    rm -f

CFLAGS += -Wextra -Wall -I$(INC) -O3

CFLAGS += -ansi -pedantic

INC =	../../include/.

LINK =	../../lib/.

NAME =  libhistory.a

SRCS =	./src/history_create_ptr_func.c \
	./src/history_putlist.c \
	./src/history_substitution.c \
	./src/history_subs_func.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	cp $(NAME) $(LINK)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test:
	(cd ../my/ && $(MAKE) re)
	cc -o putlist ./test_unit/unit_history_putlist.c -L ./ -lhistory -L$ ../my/ -lmy $(CFLAGS)

.PHONY: all clean fclean re