NAME	=	libthread.so

SRC_EXT	=	cpp
OBJ_EXT	=	o

INC_PATH	=	./inc/
SRC_PATH	=	./src/

SRC	=	$(SRC_PATH)Mutex.cpp \
		$(SRC_PATH)LockScope.cpp \
		$(SRC_PATH)Cond.cpp \

OBJ	=	$(SRC:.$(SRC_EXT)=.$(OBJ_EXT))

INC	=	-I $(INC_PATH) -I ./

CC	=	g++

CPPFLAGS	+= $(INC) -g -O3 -W -Wall -fPIC  -Wextra -pthread

# Rules

all:	$(NAME)

%.$(OBJ_EXT): %.$(SRC_EXT)
	$(CC) -o $@ -c $< $(INC) $(CPPFLAGS)

$(NAME):	$(OBJ)
	$(CC) -o $@ $^ $(INC) $(CPPFLAGS) -shared -Wl,-soname,$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all

.PHONY:	clean fclean

## END
