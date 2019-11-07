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
CFLAGS += -W -Wall -Wextra

LIB_FOLDER = ./lib/
UTILE_LIB = utile
GARBAGE_COLLECTOR_LIB = garbage_collector
MATRIX_LIB = matrix
MAP_LIB = map
STACK_LIB = stack
LINKED_LIST_LIB = linked_list
STRING_LIB = string

MYLIB = -L $(LIB_FOLDER)$(UTILE_LIB) -l$(UTILE_LIB) \
		-L $(LIB_FOLDER)$(GARBAGE_COLLECTOR_LIB) -l$(GARBAGE_COLLECTOR_LIB) \
		-L $(LIB_FOLDER)$(MATRIX_LIB) -l$(MATRIX_LIB) \
		-L $(LIB_FOLDER)$(MAP_LIB) -l$(MAP_LIB) \
		-L $(LIB_FOLDER)$(STACK_LIB) -l$(STACK_LIB) \
		-L $(LIB_FOLDER)$(LINKED_LIST_LIB) -l$(LINKED_LIST_LIB) \
		-L $(LIB_FOLDER)$(STRING_LIB) -l$(STRING_LIB) \

all: $(NAME)

$(NAME): $(OBJS)
		@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;34m$(NBR_OF_FILES)\033[0m"
		@ make -s -C $(LIB_FOLDER)$(UTILE_LIB)
		@ make -s -C $(LIB_FOLDER)$(GARBAGE_COLLECTOR_LIB)
		@ make -s -C $(LIB_FOLDER)$(MATRIX_LIB)
		@ make -s -C $(LIB_FOLDER)$(MAP_LIB)
		@ make -s -C $(LIB_FOLDER)$(STACK_LIB)
		@ make -s -C $(LIB_FOLDER)$(LINKED_LIST_LIB)
		@ make -s -C $(LIB_FOLDER)$(STRING_LIB)
		@ $(CC) -o $(NAME) $(OBJS) $(MYLIB)
		@ echo "\033[1;34mBinary : \033[1;32m$(NAME)\033[1;34m created sucesfully.\033[0m"

clean:
		@ echo "\033[3;31mRemoving: \033[0m"
		@ echo "\033[3;31m$(OBJS)\033[0m" | tr ' ' '\n'
		@ $(RM) $(OBJS)

fclean:	clean
		@ echo "\033[3;31m./$(NAME)\033[0m"
		@ $(RM) $(NAME)
		@ make fclean -s -C $(LIB_FOLDER)$(UTILE_LIB)
		@ make fclean -s -C $(LIB_FOLDER)$(GARBAGE_COLLECTOR_LIB)
		@ make fclean -s -C $(LIB_FOLDER)$(MATRIX_LIB)
		@ make fclean -s -C $(LIB_FOLDER)$(MAP_LIB)
		@ make fclean -s -C $(LIB_FOLDER)$(STACK_LIB)
		@ make fclean -s -C $(LIB_FOLDER)$(LINKED_LIST_LIB)
		@ make fclean -s -C $(LIB_FOLDER)$(STRING_LIB)

re: fclean all

%.o:	%.c
	@ echo "\033[1;34m[ OK ]\033[0m Compiling" $<
	@ $(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all clean fclean re
