
#Name of the program
NAME = push_swap

#Compilers and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

#Directories
SRCS = src
INCLUDES = -I lib/ -I src/ -I .

# Source files and object files
SRC = $(SRCS)/push_swap.c $(SRCS)/push_swap_utils.c $(SRCS)/stack_create.c $(SRCS)/stack_update.c
OBJ = $(SRC:.c=.o)

#Library
LIBFT = lib/libft.a

#Rules
all: $(LIBFT) $(NAME)

#Executable
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile the library
$(LIBFT):
	@make -C lib
	@echo "Library Compiled."

#Clean object files
clean: 
	@make -C lib clean
	rm -f $(OBJ)

#Clean all generated files
fclean: clean
	@make -C lib fclean
	rm -f $(NAME)

#Recompile everything
re: fclean all

.PHONY: all clean fclean re

