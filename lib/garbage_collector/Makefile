##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## my make file
##

NAME 	=	libgarbage_collector.a

SRCS  =	./src/create_garbage_collector.c \
		./src/add_garbage_collector.c \
		./src/destroy_garbage_collector.c \
		./src/clean_garbage_collector.c \

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
		@ echo "\033[1;34mLibrary : \033[1;32m$(NAME)\033[1;34m Created Sucesfully.\033[0m"

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
