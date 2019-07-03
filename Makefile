##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## my make file
##

NAME 	=	binary

SRCS  =	./src/main.c \

OBJS	=	$(SRCS:.c=.o)

NBR_OF_FILES := $(words $(SRCS))

CC	=	gcc

RM	=	rm -f

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra -Werror

LIB_FOLDER = ./lib/
VECTOR_LIB = vector
STACK_LIB = stack
GARBAGE_COLLECTOR_LIB = garbage_collector
LINKED_LIST_LIB = linked_list

MYLIB = -L $(LIB_FOLDER)$(VECTOR_LIB) -l$(VECTOR_LIB) -L $(LIB_FOLDER)$(STACK_LIB) -l$(STACK_LIB) -L $(LIB_FOLDER)$(GARBAGE_COLLECTOR_LIB) -l$(GARBAGE_COLLECTOR_LIB) -L $(LIB_FOLDER)$(LINKED_LIST_LIB) -l$(LINKED_LIST_LIB)

all: $(NAME)

$(NAME): mylib $(OBJS)
		@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;34m$(NBR_OF_FILES)\033[0m"
		@ $(CC) -o $(NAME) $(OBJS) $(MYLIB)
		@ echo "\033[1;33m--------------- Binary : \033[1;31m$(NAME)\033[1;33m Created Sucesfully. --------------- \033[0m"

mylib:
	@ make -C $(LIB_FOLDER)$(LINKED_LIST_LIB)
	@ make -C $(LIB_FOLDER)$(GARBAGE_COLLECTOR_LIB)
	@ make -C $(LIB_FOLDER)$(STACK_LIB)
	@ make -C $(LIB_FOLDER)$(VECTOR_LIB)

clean:
		@ $(RM) $(OBJS)

fclean:	clean
		@ make fclean -C $(LIB_FOLDER)$(LINKED_LIST_LIB)
		@ make fclean -C $(LIB_FOLDER)$(GARBAGE_COLLECTOR_LIB)
		@ make fclean -C $(LIB_FOLDER)$(STACK_LIB)
		@ make fclean -C $(LIB_FOLDER)$(VECTOR_LIB)
		@ $(RM) $(NAME)

re: fclean all

%.o:	%.c
	@ echo "\033[1;34m[ OK ]\033[0m Compiling" $<
	@ $(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all clean fclean re
