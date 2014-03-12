##
## Makefile for Makefile in /home/platel_k/projet/minilibX/tp1
## 
## Made by kevin platel
## Login   <platel_k@epitech.net>
## 
## Started on  Wed Nov  9 12:58:27 2011 kevin platel
## Last update Wed Nov 23 15:17:58 2011 kevin platel
##

NAME	= tp

SRC	= main.c \
	init_point.c \
	init_my_ptr.c \
	init_img.c \
	my_ppt.c \
	line.c \
	img_line.c

OBJ	= $(SRC:.c=.o)

CC	= gcc

CCFLAGS	= -Wall -Wextra

LIB	= -L/usr/lib64 -lmlx_x86_64-linux -L/usr/lib64/X11 -lXext -lX11 -I .

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(CCFLAGS)

clean:
	rm -f $(NAME)