##
## EPITECH PROJECT, 2020
## rrostring
## File description:
## makefile
##

NAME	= matchstick

CC	= gcc

RM	= rm -f

SRCS	= 	./src/main.c \
	  	./src/my/my_putstr.c \
	  	./src/my/my_atoi.c \
	  	./src/my/my_str_isnum.c \
	  	./src/game_loop.c \
	  	./src/matchstick.c \
	  	./src/pyramid.c \
	  	./src/my/modify_Str.c \
	  	./src/my/my_put_nbr.c \
	  	./src/my/my_putchar.c \
	  	./src/my/my_strdup.c \
		./src/ai_move.c \
		./src/check_end.c \
		./src/count_stick.c \
		./src/modify_Map.c \
		./src/middle.c \
		./src/player_move.c \
		./src/select_line.c \
		./src/my/my_printf.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
