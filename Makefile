NAME = linked

CC = cc

CFLAGS = #-O3 -Wall -Wextra -fsanitize=address -g #-Werror

SRCS = lists_aux.c \
	   main.c \
	   utils1.c

OBJS	= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all