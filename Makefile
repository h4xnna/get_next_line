NAME = gnl
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re