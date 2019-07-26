##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## my make file
##

NAME 	=	libstack.a

SRCS  =	./src/clear_stack.c \
		./src/create_stack.c \
		./src/destroy_stack.c \
		./src/dup_stack.c \
		./src/empty_stack.c \
		./src/pop_stack.c \
		./src/push_stack.c \
		./src/recycle_stack.c \
		./src/size_stack.c \
		./src/swap_stack.c \
		./src/top_stack.c \
		./src/convert_stack.c \
		./src/rotate_stack.c \

OBJS	=	$(SRCS:.c=.o)

NBR_OF_FILES := $(words $(SRCS))

AR = ar rc

RM	=	rm -f

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;34m$(NBR_OF_FILES)\033[0m"
		@ $(AR) $(NAME) $(OBJS)
		@ echo "\033[1;34mLibrary : \033[1;32m$(NAME)\033[1;34m created sucesfully.\033[0m"

clean:
		@ echo "\033[3;31mRemoving: \033[0m"
		@ echo "\033[3;31m$(OBJS)\033[0m" | tr ' ' '\n'
		@ $(RM) $(OBJS)

fclean:	clean
		@ echo "\033[3;31m./$(NAME)\033[0m"
		@ $(RM) $(NAME)

re: fclean all

%.o:	%.c
	@ echo "\033[1;34m[ OK ]\033[0m Compiling" $<
	@ $(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all clean fclean re
