NAME = pushswap

CC = cc
CFALGS = -Wall -Werror -Wextra -g

SOURCES_FILES = stack.c push_swap.c checkers.c rules.c quick_sort.c \
				target.c sort.c costs.c
				
SRC = $(addprefix $(SRC_DIR)/, $(SOURCES_FILES))

OBJECTS = $(addprefix $(OBJECTS_DIR)/, $(SOURCES_FILES:.c=.o))
OBJECTS_DIR = objects
SRC_DIR = srcs

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = ./includes/libft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS) 
	@echo "Building..."
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
	@echo "Ready!"

$(OBJECTS_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJECTS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) bonus -s --no-print-directory

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

clean:
	@rm -rf $(OBJECTS_DIR)
	@make -C $(LIBFT_DIR) clean -s
	@echo "Cleaned!"

fclean: clean
	@make -C $(LIBFT_DIR) fclean -s --no-print-directory
	@rm -rf $(NAME)

re: fclean all
	@echo "Rebuilded!"

.PHONY: all clean fclean re
