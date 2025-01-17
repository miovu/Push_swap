NAME = push_swap.a

SOURCES = 

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $?
	echo "Creating library" $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJECTS) 
	echo "Removing object files"

fclean: clean
	rm -f $(NAME)
	echo "Removing library $(NAME)"

re: fclean all
	echo "Rebuilding library" 

.PHONY: all clean fclean re