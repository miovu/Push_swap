NAME = push_swap

CC = cc
CFALGS = -Wall -Werror -Wextra -g

SOURCES_FILES = checkers.c costs.c moves.c push_swap.c quick_sort.c \
				rules.c rules2.c sort.c stack.c stack2.c target.c \
				
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
