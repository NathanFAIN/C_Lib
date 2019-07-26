##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## my make file
##

NAME 	=	libvector.a

SRCS  =	./src/add_vector.c \
		./src/cmp_vector_id.c \
		./src/convert_vector.c \
		./src/create_vector.c \
		./src/create_table.c \
		./src/destroy_vector.c \
		./src/get_all_vector.c \
		./src/get_vector_size.c \
		./src/get_vector.c \
		./src/hash_vector_id.c \
		./src/recycle_vector.c \
		./src/remove_vector.c \
		./src/clean_vector.c \

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
