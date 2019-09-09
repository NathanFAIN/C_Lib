##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## my make file
##

NAME 	=	liblinked_list.a

SRCS  =	./src/cat_back_linked_list.c \
		./src/cat_front_linked_list.c \
		./src/clear_linked_list.c \
		./src/create_link.c \
		./src/create_linked_list.c \
		./src/destroy_linked_list.c \
		./src/dup_linked_list.c \
		./src/empty_linked_list.c \
		./src/foreach_linked_list.c \
		./src/get_at_linked_list.c \
		./src/insert_at_linked_list.c \
		./src/pop_back_linked_list.c \
		./src/pop_front_linked_list.c \
		./src/push_back_linked_list.c \
		./src/push_front_linked_list.c \
		./src/recycle_linked_list.c \
		./src/remove_at_linked_list.c \
		./src/remove_if_linked_list.c \
		./src/remove_link.c \
		./src/reverse_linked_list.c \
		./src/size_linked_list.c \
		./src/sort_linked_list.c \
		./src/top_back_linked_list.c \
		./src/top_front_linked_list.c \

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
