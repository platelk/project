##
## Makefile for 42sh in /home/leprov_a//depot/42sh/src/config
## 
## Made by alexis leprovost
## Login   <leprov_a@epitech.net>
## 
## Started on  Sun Apr 15 20:02:07 2012 alexis leprovost
## Last update Wed Apr 18 17:42:48 2012 alexis leprovost
##

NAME=	libconfig.a

CFLAGS=	-Wall -Wextra -Werror -I$(INC) -L $(LINK) -lmy

SRC=	$(wildcard ./src/*.c)

OBJ=	$(SRC:.c=.o)

INC=	../../include/.

RM=	rm -f

LINK=	../../lib/.

all:	$(NAME)

%.o:		%.c
		$(CC) -c $^ -o $@ $(CFLAGS)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@cp $(NAME) $(LINK)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

test:	re
	@(cd ./../my/ && $(MAKE) re)
	@(cd ./../env/ && $(MAKE) re)
	cc -o parser ./test_unit/unit_config_parser.c -L ./ -lconfig -L$(LINK) -lmy -L$(LINK) -lenv $(CFLAGS)
	cc -o history ./test_unit/unit_config_history.c -L ./ -lconfig -L$(LINK) -lmy -L$(LINK) -lenv $(CFLAGS)
	cc -o alias ./test_unit/unit_config_alias.c -L ./ -lconfig -L$(LINK) -lmy -L$(LINK) -lenv $(CFLAGS)
	cc -o prompt ./test_unit/unit_config_prompt.c -L ./ -lconfig -L$(LINK) -lmy -L$(LINK) -lenv $(CFLAGS)
	cc -o globing ./test_unit/unit_config_globing.c -L ./ -lconfig -L$(LINK) -lmy -L$(LINK) -lenv $(CFLAGS)
	cc -o env ./test_unit/unit_config_env.c -L ./ -lconfig -L$(LINK) -lmy -L$(LINK) -lenv $(CFLAGS)