##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## my make file
##

NAME 	=	libstring.a

SRCS  =	./src/cat_back_string.c \
		./src/cat_front_string.c \
		./src/clear_string.c \
		./src/cmp_string.c \
		./src/create_string.c \
		./src/cut_back_string.c \
		./src/cut_front_string.c \
		./src/destroy_string.c \
		./src/dup_string.c \
		./src/empty_string.c \
		./src/get_at_string.c \
		./src/get_back_string.c \
		./src/get_front_string.c \
		./src/insert_at_string.c \
		./src/len_string.c \
		./src/parce_string.c \
		./src/recycle_string.c \
		./src/replace_at_string.c \
		./src/reverse_string.c \
		./src/rotate_string.c \
		./src/set_string.c \
		./src/swap_at_string.c \
		./src/swap_string.c \
		./src/to_char_string.c \

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
