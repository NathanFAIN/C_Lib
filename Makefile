##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## my make file
##

NAME 	=	binary

SRCS  =	./src/main.c \

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

RM	=	rm -f

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra -Werror

VECTOR_LIB_FOLDER = ./lib/vector/
STACK_LIB_FOLDER = ./lib/stack/

MYLIB = -L $(VECTOR_LIB_FOLDER) -lvector -L $(STACK_LIB_FOLDER) -lstack

all: $(NAME)

$(NAME): mylib $(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(MYLIB)

mylib:
	make -C $(STACK_LIB_FOLDER)
	make -C $(VECTOR_LIB_FOLDER)

clean:
		$(RM) $(OBJS)
		make clean -C $(STACK_LIB_FOLDER)
		make clean -C $(VECTOR_LIB_FOLDER)

fclean:	clean
		$(RM) $(NAME)
		make fclean -C $(STACK_LIB_FOLDER)
		make fclean -C $(VECTOR_LIB_FOLDER)

re: fclean all
