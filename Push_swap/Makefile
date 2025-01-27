NAME = pushswap.a

SOURCES = splitargs.c checkers.c

SRCS_DIR = src
LIBFT_DIR = libft
PRINTF_DIR = libft/printf

SRCS = $(wildcard $(SRCS_DIR)/*.c)
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)
PRINTF_SRCS = $(wildcard $(PRINTF_DIR)/*.c)

LIB = $(SRCS) $(LIBFT_SRCS)

PRINTF = $(SRCS) $(PRINTF_SRCS)

OBJECTS = $(SOURCES:.c=.o) $(LIB:.c=.o) $(PRINTF:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) 
	ar rcs $@ $^
	echo "Creating $(NAME)"

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJECTS)
	echo "Removing object files"

fclean: clean
	rm -f $(NAME)
	echo "Removing $(NAME)"

re: fclean all
	echo "Rebuilding library" 

.PHONY: all clean fclean re
