# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 10:25:21 by cayamash          #+#    #+#              #
#    Updated: 2025/01/17 14:14:56 by cayamash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name of the program
NAME = push_swap

#Compilers and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

#Directories
SRCS = src
INCLUDES = -I lib/ -I src/ -I .

# Source files and object files
SRC = $(SRCS)/push_swap.c $(SRCS)/check_args.c $(SRCS)/operations.c \
		$(SRCS)/stack_create.c $(SRCS)/stack_utils.c $(SRCS)/find_target.c\
		$(SRCS)/calculate_index.c $(SRCS)/push_to_stack.c
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

