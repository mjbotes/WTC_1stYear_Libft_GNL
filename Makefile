NAME = get_next_line.a

SRCS = get_next_line.c	

OBJECTS = get_next_line.o

INCLUDES = get_next_line.h

all: $(NAME)

$(NAME): $(SRCS) get_next_line.h
	gcc -Wall -Wextra -Werror -I $(INCLUDES) -c $(SRCS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

