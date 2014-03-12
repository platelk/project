##
## Makefile for my in /home/leprov_a//depot/42sh/src/config/lib
## 
## Made by alexis leprovost
## Login   <leprov_a@epitech.net>
## 
## Started on  Sun Apr 15 21:18:57 2012 alexis leprovost
##

NAME	=	libmy.a

LINK	=	src

CFLAGS	=	-Wextra -Werror -I$(INC)

SRC	=	$(LINK)/my_putstr.c \
		$(LINK)/check_base.c \
		$(LINK)/concat.c \
		$(LINK)/get_next_line.c \
		$(LINK)/isanumber.c \
		$(LINK)/is_singlestr.c \
		$(LINK)/malloc_tabint.c \
		$(LINK)/my_clstr.c \
		$(LINK)/my_free_tab.c\
		$(LINK)/my_getnbr.c \
		$(LINK)/my_putchar.c \
		$(LINK)/my_revstr.c \
		$(LINK)/my_strcat.c \
		$(LINK)/my_strcmp.c \
		$(LINK)/my_strcpy.c \
		$(LINK)/my_strdup.c \
		$(LINK)/my_strlen.c \
		$(LINK)/my_strmcat.c \
		$(LINK)/my_strncmp.c \
		$(LINK)/my_strtok.c \
		$(LINK)/my_tablen.c \
		$(LINK)/strsearch.c \
		$(LINK)/xmalloc.c \
		$(LINK)/xopen.c \
		$(LINK)/xtime.c \

OBJ	=	$(SRC:.c=.o)

INC	=	../../include/

RM	=	rm -f

all:	$(NAME)

%.o:		%.c
		$(CC) -c $^ -o $@ $(CFLAGS)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all