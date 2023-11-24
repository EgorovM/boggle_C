# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = boggle
SRC = main.c boggle.c
OBJ = $(SRC:.c=.o)

# Default rule
all: $(NAME)

# Compile the program
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Object file rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJ)

# Full clean (objects and binary)
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re